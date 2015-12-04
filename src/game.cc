#include <iostream>
#include <cstdlib>
#include <math.h>
#include <fstream>
#include "game.h"
#include "level.h"
#include "filelevel.h"
#include "normallevel.h"
#include "cell.h"
#include "player.h"
#include "shade.h"
#include "drow.h"
#include "vampire.h"
#include "goblin.h"
#include "troll.h"
#include "dwarf.h"
#include "elf.h"
#include "orc.h"
#include "merchant.h"
#include "halfling.h"
#include "dragon.h"

using namespace std;

Game::Game():gamestate(0), curFloor(1) {
    nullCells();
    fromFile = false;
    playerCell = NULL;
    masterTurnFlag = true;
    actionEvent = new ActionEvent();
    merchWillAttack = false;
}

/* Game(filedata)
 * Constructor : Takes full dump of file data and separates it into 5 different
 *   2D character arrays
 */
Game::Game(char data[HEIGHT * 5][WIDTH]):gamestate(0), curFloor(1) {
    for (int f = 0; f < 5; f++) {
        for (int r = 0; r < HEIGHT; r++) {
            for (int c = 0; c < WIDTH; c++) {
                fileMaps[f][r][c] = data[(f * HEIGHT) + r][c];
            }
        }
    }
    nullCells();
    fromFile = true;
    playerCell = NULL;
    masterTurnFlag = true;
    actionEvent = new ActionEvent();
    merchWillAttack = false;
}

Game::~Game() {}


void Game::setupCellBlockRadii(){
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            int row = i;
            int col = j;
            if (((row - 1) >= 0) && ((col - 1) >= 0)) {
                cellGrid[i][j]->addNeighbourBlock(cellGrid[i-1][j-1]);
            }
            if ((row - 1) >= 0) {
                cellGrid[i][j]->addNeighbourBlock(cellGrid[i-1][j]);
            }
            if (((row - 1) >= 0) && ((col + 1) < WIDTH)) {
                cellGrid[i][j]->addNeighbourBlock(cellGrid[i-1][j+1]);
            }
            if ((col - 1) >= 0) {
                cellGrid[i][j]->addNeighbourBlock(cellGrid[i][j-1]);
            }
            if ((col + 1) < WIDTH) {
                cellGrid[i][j]->addNeighbourBlock(cellGrid[i][j+1]);
            }
            if (((row + 1) < HEIGHT) && ((col - 1) >= 0)) {
                cellGrid[i][j]->addNeighbourBlock(cellGrid[i+1][j-1]);
            }
            if ((row + 1) < HEIGHT) {
                cellGrid[i][j]->addNeighbourBlock(cellGrid[i+1][j]);
            }
            if (((row +1) < HEIGHT) && ((col + 1) < WIDTH)) {
                cellGrid[i][j]->addNeighbourBlock(cellGrid[i+1][j+1]);
            }
        }
    }
}

void Game::clearMap() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            cellGrid[i][j]->removeGameObject();
//            delete cellGrid[i][j];
        }
    }
    cout << "Map cleared" << endl;
}

/* load()
 * If !fromFile: randomly generates player position, enemies, gold, potions on the floor
 * If fromFile: generates floor layout specified in file
 */
void Game::load() {
    if (fromFile) {
        FileLevel level = FileLevel();
        playerCell = level.initLevel(cellGrid, fileMaps[curFloor - 1]);
        playerCell->setGameObject('@', player);
        cellGrid[playerCell->getRow()][playerCell->getColumn()]->setGameObject('@', player);
        if (curFloor == 1) {
            setupCellBlockRadii();
        }
    } else {
        char blankMap[HEIGHT][WIDTH];
        string file = "res/map-layout-newline";
        ifstream fs;
        fs.open(file.c_str());
        if (fs.is_open()) {
            cout << "file is open" << endl;
            fs >> noskipws;
            char cell;
            for (int r = 0; r < HEIGHT; r++) {
                for (int c = 0; c < WIDTH; c++) {
                    fs >> cell;
                    if (cell == '\n') {
                        fs >> cell;
                    }
                    if (fs.fail()) {
                        cerr << "Error: file was not read properly" << endl;
                    }
                    blankMap[r][c] = cell;
                }
            }
            fs.close();
        }else{
            cout << "File could not open" << endl;
        }
        NormalLevel level = NormalLevel(); //this will call init
        playerCell = level.initLevel(cellGrid, blankMap); //init player here
        playerCell->setGameObject('@', player);
        cellGrid[playerCell->getRow()][playerCell->getColumn()]->setGameObject('@', player);
        setupCellBlockRadii();
    }
}

void Game::nullCells() {
    for (int r = 0; r < HEIGHT; r++) {
        for (int c = 0; c < WIDTH; c++) {
            cellGrid[r][c] = new Cell(r, c);
        }
    }
}
int Game::enemyAttack(float enemyAtk, float playerDefence){
    int damage = 0;
    int fiftyFifty;
    fiftyFifty = rand() % 2 + 1;
    if (1 == fiftyFifty) {
        damage = ceil((100.00/(100.00 + playerDefence)) * enemyAtk);
    }
    return damage;
}

//PC deals 5 damage to H (135 HP). H deals 5 damage to PC.
//actionEvent->setEvent("You attack.");

//update cells ENEMIES TURN
void Game::updateEnemy(){
    for (int r = 0; r < HEIGHT; r++) {
        for (int c = 0; c < WIDTH; c++) {
            Cell *tmpCell = cellGrid[r][c];
            GameObject *tmpGObj = tmpCell->getGameObject();
            if (tmpGObj && masterTurnFlag != tmpGObj->getTurnFlag()) {
                char cellChar = tmpCell->getCellChar();
                if (eCatalogue.isEnemy(cellChar)) {
                    if(!tmpCell->isPlayerWithinBlock() || ((cellChar == 'M') && (!merchWillAttack))){
                        //enemy not within one block radius so it must move
                        tmpCell->randomizeEnemyMovement();
                    }else{
                        float enemyAtk = static_cast<float>(eCatalogue.getAtk(cellChar));
                        float playerDefence = static_cast<float>(player->getDef()); //need to setup player here
                        int damage = enemyAttack(enemyAtk, playerDefence);
                        
                        // Orc attack on Goblin 50% more damage
                        if ((cellChar == 'O') && (player->getRace() == "Goblin")) {
                            damage = floor(damage * 1.5);
                        }
                        
                        string race = eCatalogue.getRace(cellChar);
                        if (damage == 0) {
                            actionEvent->setEvent(race + " has missed an attack.");
                        }else{
                            actionEvent->setEvent(race + " deals " + to_string(damage) + " damage against you!");
                        }
                        
                        player->setDamageHp(damage);
                        if(player->isSlain()){
                            actionEvent->addEvent("You have been slain.");
                        }
                        
                        // Elf get two chances to attack, except on Drow
                        if ((cellChar == 'E') && (player->getRace() != "Drow")){
                            damage = enemyAttack(enemyAtk, playerDefence);
                            if (damage == 0) {
                                actionEvent->setEvent(race + " has missed an attack.");
                            }else{
                                actionEvent->setEvent(race + " deals " + to_string(damage) + " damage against you!");
                            }
                            player->setDamageHp(damage);
                            if(player->isSlain()){
                                actionEvent->addEvent("You have been slain.");
                            }
                        }
                    }
                }
                //show GameObject has had turn
                tmpGObj->switchTurnFlag();
            }
        }
    }
    masterTurnFlag = !masterTurnFlag;
}



/* Game::notify(mode, direction)
 * Based on mode, tells the Player to perform an action (MOVE, USE, ATTACK)
 *   in the specified direction
 * int, int -> void
 */
void Game::notify(int mode, int direction) {
    int playerRow = playerCell->getRow();
    int playerCol = playerCell->getColumn();
    int checkRow = playerRow, checkCol = playerCol;
    
    if (direction == 1 || direction == 2 || direction == 3) {
        checkRow--;
    }
    if (direction == 1 || direction == 4 || direction == 6) {
        checkCol--;
    }
    if (direction == 6 || direction == 7 || direction == 8) {
        checkRow++;
    }
    if (direction == 3 || direction == 5 || direction == 8) {
        checkCol++;
    }
    
    char check_char = cellGrid[checkRow][checkCol]->getCellChar();
    
    if (mode == USE) {
        if (check_char == 'P') {
            GameObject* go = cellGrid[checkRow][checkCol]->getGameObject();
            actionEvent->setEvent(player->use(dynamic_cast<Potion*>(go)));
            delete go;
            cellGrid[checkRow][checkCol]->removeGameObject();
        } else {
            actionEvent->setEvent("There is nothing here to use.");
        }
    //To Do set merchWillAttack = true; if you attack a merchant
    } else if (mode == ATTACK) {
        actionEvent->setEvent("You attack.");
    } else if (mode == MOVE) {
        if (check_char == '.' || check_char == '#' || check_char == '+') {
            cellGrid[checkRow][checkCol]->setGameObject('@', player);
            cellGrid[playerRow][playerCol]->removeGameObject();
            playerCell->setRow(checkRow);
            playerCell->setColumn(checkCol);
            updateEnemy();
        } else if (check_char == 'G') {
            GameObject* go = cellGrid[checkRow][checkCol]->getGameObject();
            actionEvent->addEvent(player->use(dynamic_cast<Treasure*>(go)));
            cellGrid[checkRow][checkCol]->setGameObject('@', player);
            cellGrid[playerRow][playerCol]->removeGameObject();
            playerCell->setRow(checkRow);
            playerCell->setColumn(checkCol);
            updateEnemy();
        } else if (check_char == '\\') {
            if (curFloor == 5) {
                actionEvent->setEvent("You are freed from the dungeon!");
                gamestate = MENU;
            } else {
                curFloor++;
                clearMap();
                load();
                actionEvent->setEvent("Stepping down the staircase, you move deeper into the dungeon.");
            }
        } else {
            actionEvent->setEvent("There is something blocking your path.");
        }
    }
}
/* Game::getState()
 * Returns the value of the private gamestate field
 * void -> int
 */
int Game::getState() {
    return gamestate;
}

/* Game::setState(s)
 * Sets the value of the private gamestate field to s
 * int -> void
 */
void Game::setState(int s) {
    gamestate = s;
}

Cell* Game::getPlayerCell() {
    return playerCell;
}

void Game::setPlayerCell(Cell* c) {
    playerCell = c;
}

Cell* Game::getCell(int row, int col) {
    return cellGrid[row][col];
}

void Game::setCell(int row, int col, Cell* c) {
    if (cellGrid[row][col]) {
        delete cellGrid[row][col];
    }
    cellGrid[row][col] = c;
}

Player* Game::getPlayer() {
    return player;
}

/* Game::setPlayer(race)
 * Deletes the current Player pointer (if it is not NULL), and creates a
 *   new Player of Race race on the heap. Since this method is only called
 *   by Controller at the beginning of a game, it also calls Game::init() to
 *   begin generating the floor
 */
void Game::setPlayer(int race) {
    if (player) {
        delete player;
    }
    if (race == SHADE) {
        player = new Shade();
    } else if (race == DROW) {
        player = new Drow();
    } else if (race == VAMPIRE) {
        player = new Vampire();
    } else if (race == TROLL) {
        player = new Troll();
    } else if (race == GOBLIN) {
        player = new Goblin();
    }
}

void Game::setPlayer(Player *p) {
    player = p;
}

ActionEvent* Game::getActionEvent() {
    return actionEvent;
}

void Game::setActionEvent(ActionEvent* ae) {
    actionEvent = ae;
}

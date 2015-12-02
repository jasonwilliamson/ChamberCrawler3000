#include <iostream>
#include <cstdlib>
#include <math.h>
#include "game.h"
#include "level.h"
#include "filelevel.h"
#include "cell.h"

using namespace std;

Game::Game():gamestate(0), curFloor(1) {
    nullCells();
    fromFile = false;
    playerCell = NULL;
    masterTurnFlag = true;
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

/* load()
 * If !fromFile: randomly generates player position, enemies, gold, potions on the floor
 * If fromFile: generates floor layout specified in file
 */
void Game::load() {
    if (fromFile) {
        FileLevel level = FileLevel();
        playerCell = level.initLevel(cellGrid, fileMaps[curFloor - 1]);
    } else {
        //levelCreator->generate(cellGrid);
    }
    
}

void Game::nullCells() {
    for (int r = 0; r < HEIGHT; r++) {
        for (int c = 0; c < WIDTH; c++) {
            cellGrid[r][c] = new Cell(r, c);
        }
    }
    setupCellBlockRadii();
}

/*
 int iSecret, iGuess;
 
 //initialize random seed:
srand (time(NULL));

// generate secret number between 1 and 10:
iSecret = rand() % 10 + 1;

 */

//update cells ENEMIES TURN
void Game::updateEnemy(){
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            Cell *tmpCell = cellGrid[i][j];
            
            //check if enemy has had turn
            if (masterTurnFlag != tmpCell->getGameObject()->getTurnFlag()) {
                char cellChar = tmpCell->getCellChar();
                if (eCatalogue.isEnemy(cellChar)) {
                    if(tmpCell->isPlayerWithinBlock()){
                        int enemyAtk = eCatalogue.getAtk(cellChar);
                        int playerDefense = player->getDef();
                        int fiftyFifty;
                        //50/50 change of enemy attack missing
                        srand( static_cast<unsigned int>(time(NULL)));
                        fiftyFifty = rand() % 2 + 1;
                        if (1 == fiftyFifty) {
                            //Damage(Def ender) = ceiling((100/(100+Def (Def ender)))∗Atk(Attacker))
                            int damage = ceil((100/100 + playerDefense) * enemyAtk);
                            player->setDamageHp(damage);
                            if(player->isSlain()){
                                cout << "player has been slain" << endl;
                            }
                        }else{
                            //attack missed
                            cout << "enemies attack missed" << endl;
                        }
                    }else{
                        //enemy not within one block radius so it must move
                        tmpCell->randomizeEnemyMovement();
                    }
                }
                //show GameObject has had turn
                tmpCell->getGameObject()->switchTurnFlag();
            }
        }
    }
}

/* Game::notify(mode, direction)
 * Based on mode, tells the Player to perform an action (MOVE, USE, ATTACK)
 *   in the specified direction
 * int, int -> void
 */
void Game::notify(int mode, int direction) {
    if (mode == USE) {
        cout << "Item used" << endl;
        //use item in direction dir
    } else if (mode == ATTACK) {
        cout << "ATTACK!" << endl;
        //attack in direction dir
    } else if (mode == MOVE) {
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
        if (check_char == '.' || check_char == '#' || check_char == '+') {
            cellGrid[checkRow][checkCol]->setGameObject('@', cellGrid[playerRow][playerCol]->getGameObject());
            cellGrid[playerRow][playerCol]->setGameObject(check_char, NULL);
            playerCell->setRow(checkRow);
            playerCell->setColumn(checkCol);
        } else {
            //ActionEvent
            //action->update("You cannot go there.");
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
    /*
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
    }
    */
}

void Game::setPlayer(Player *p) {
    player = p;
}

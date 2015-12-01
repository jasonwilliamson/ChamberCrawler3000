#include <iostream>
#include "game.h"
#include "level.h"
#include "filelevel.h"
#include "cell.h"

using namespace std;

Game::Game():gamestate(0), curFloor(1) {
    nullCells();
    fromFile = false;
    playerCell = NULL;
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
}

Game::~Game() {}

/* load()
 * If !fromFile: randomly generates player position, enemies, gold, potions on the floor
 * If fromFile: generates floor layout specified in file
 */
void Game::load() {
    if (fromFile) {
        FileLevel level = FileLevel();
        level.initLevel(cellGrid, fileMaps[curFloor - 1]);
        //levelCreator->initL
        //levelCreator = FileLevel(cellGrid, fileMaps[curFloor - 1]);
        //levelCreator->generate(cellGrid, fileMaps[curFloor - 1]);
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
}

/* Game::notify(mode, direction)
 * Based on mode, tells the Player to perform an action (MOVE, USE, ATTACK)
 *   in the specified direction
 * int, int -> void
 */
void Game::notify(int mode, int direction) {

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

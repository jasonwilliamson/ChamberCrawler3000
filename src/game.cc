#include "game.h"

using namespace std;

Game::Game():gamestate(0) {
}

Game::Game(char filemap[HEIGHT][WIDTH]):gamestate(0) {
    //give filemap to level
}

Game::~Game() {
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

/* Game::setPlayer(race)
 * Deletes the current Player pointer (if it is not NULL), and creates a
 *   new Player of Race race on the heap
 */
void Game::setPlayer(int race) {

}

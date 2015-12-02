#include "controller.h"
#include <iostream> //remove after Game implementation and remove couts

using namespace std;

Controller::Controller() {
    game = new Game();
    display = new Display();
}

Controller::Controller(char filegrid[HEIGHT * 5][WIDTH]) {
    game = new Game(filegrid);
    display = new Display();
}

Controller::~Controller() {
    delete game;
    delete display;
}

/* play()
 * Takes all user input and passes it to Game 
 * 
 * ALL GAMESTATES
 * q: quits game
 *
 * GAMESTATE 0 (pregame)
 * s, d, v, g, t: starts a new game where the player is the specified race
 *   (s)hade
 *   (d)row
 *   (v)ampire
 *   (g)oblin
 *   (t)roll
 *
 * GAMESTATE 1 (ingame)
 * r: restarts current game, allows player to choose new race
 * [direction] (one of nw no ne we ea sw so se): moves player one unit in
 *   the specified direction
 * u [direction]: attempts to use an item (potion) one unit away from the
 *   the player (in the specified direction)
 * a [direction]: attempts to attack an enemy one unit away from the player
 *   (in the specified direction)
 * 
 * void -> void
 */
void Controller::play() {
    string cmd;
    while (true) {
        if (game->getState() == MENU) {
            display->draw(MENU);
        } else if (game->getState() == PLAY) {
            display->draw(PLAY);
        }

        cin >> cmd;
        if (cin.fail() || cmd == "q") {
            display->draw(-1);
            break;
        }

        if (game->getState() == MENU) {
            if (cmd == "s" || cmd == "d" || cmd == "v" || cmd == "g" || cmd == "t") {
                if (cmd == "s") {
                    game->setPlayer(SHADE);
                } else if (cmd == "d") {
                    game->setPlayer(DROW);
                } else if (cmd == "v") {
                    game->setPlayer(VAMPIRE);
                } else if (cmd == "g") {
                    game->setPlayer(GOBLIN);
                } else if (cmd == "t") {
                    game->setPlayer(TROLL);
                }
                game->load();
                game->setState(PLAY);
                updateDisplay();
            } else {
                display->draw(-2);
            }
        } else if (game->getState() == PLAY) {
            if (cmd == "r") {
                // Restart Game
                game->setState(MENU);
            } else if (cmd == "u") {
                string input;
                cin >> input;
                if (cin.fail()) {
                    break;
                } else {
                    int dir = direction(input);
                    if (dir != 0) {
                        game->notify(USE, dir);
                        updateDisplay();
                    } else {
                        display->draw(-2);
                    }
                }
            } else if (cmd == "a") {
                string input;
                cin >> input;
                if (cin.fail()) {
                    break;
                } else {
                    int dir = direction(input);
                    if (dir != 0) {
                        game->notify(ATTACK, dir);
                        updateDisplay();
                    } else {
                        display->draw(-2);
                    }
                }
            } else {
                int dir = direction(cmd);
                if (dir != 0) {
                    game->notify(MOVE, dir);
                    updateDisplay();
                } else {
                    display->draw(-2);
                }
            }
        }
    }
}

void Controller::updateDisplay() {
    for (int r = 0; r < HEIGHT; r++) {
        for (int c = 0; c < WIDTH; c++) {
            display->updateMap(r, c, game->getCell(r, c)->getCellChar());
        }
    }
    //display->updateCharacter(game->getPlayer()->getRace(),
    //                         game->getPlayer()->getGold(),
    //                         game->getPlayer()->getHealth(),
    //                         game->getPlayer()->getAttack(),
    //                         game->getPlayer()->getDefense());
    //display->updateMap(game->getPlayerCell()->getRow(),
    //                   game->getPlayerCell()->getColumn(),
    //                   game->getPlayerCell()->getDisplayCharacter());
    //FINDME
}

/* direction(input)
 * Returns an integer corresponding with the cardinal direction input. Returns 
 *   0 if input is not a valid direction.
 * 
 * nw no ne     1  2  3
 * we    ea --> 4     5
 * sw so se     6  7  8
 *
 * string -> int
 */
int direction(string input) {
    if (input == "nw") { return 1; }
    else if (input == "no") { return 2; }
    else if (input == "ne") { return 3; }
    else if (input == "we") { return 4; }
    else if (input == "ea") { return 5; }
    else if (input == "sw") { return 6; }
    else if (input == "so") { return 7; }
    else if (input == "se") { return 8; }
    else { return 0; }
}

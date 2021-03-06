#include "controller.h"
#include <iostream> //remove after Game implementation and remove couts
#include <sstream>

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
    int rep = 1;
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
                game->getActionEvent()->setEvent("You awaken in a cold, dark chamber.");
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
                    int dir = direction(input, USE);
                    if (dir != 0) {
                        game->notify(USE, dir);
                    } else {
                        game->getActionEvent()->setEvent("That is not a valid action");
                    }
                }
            } else if (cmd == "a") {
                string input;
                cin >> input;
                if (cin.fail()) {
                    break;
                } else {
                    int dir = direction(input, ATTACK);
                    if (dir != 0) {
                        game->notify(ATTACK, dir);
                    } else {
                        game->getActionEvent()->setEvent("That is not a valid action");
                    }
                }
            } else {
                istringstream ss(cmd);
                if (ss >> rep) {
                    cin >> cmd;
                } else {
                    rep = 1;
                }
                for (int i = 0 ; i < rep; i++) {
                    game->getActionEvent()->setEvent("You move");
                    int dir = direction(cmd, MOVE);
                    if (dir != 0) {
                        game->notify(MOVE, dir);
                    } else {
                        game->getActionEvent()->setEvent("That is not a valid action");
                    }
                }
                rep = 1;
            }
            updateDisplay();
        }
        game->getActionEvent()->clearEvent();
    }
}

void Controller::updateDisplay() {
    for (int r = 0; r < HEIGHT; r++) {
        for (int c = 0; c < WIDTH; c++) {
            display->updateMap(r, c, game->getCell(r, c)->getCellChar());
        }
    }
    if (game->getPlayer()) {
        display->updateCharacter(game->getPlayer()->getRace(),
                game->getPlayer()->getGold(),
                game->getPlayer()->getHp(),
                game->getPlayer()->getBoosterAtk(),
                game->getPlayer()->getBoosterDef());
        display->updateMap(game->getPlayerCell()->getRow(),
                game->getPlayerCell()->getColumn(),
                game->getPlayerCell()->getCellChar());
        display->updateAction(game->getActionEvent()->getEvent());
    } else {
        cout << "Player not initialized" << endl;
    }
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
int Controller::direction(string input, int mode) {
    if (input == "nw") { 
        if (mode == MOVE) {
            game->getActionEvent()->addEvent("north-west.");
        }
        return 1; 
    } else if (input == "no") { 
        if (mode == MOVE) {
            game->getActionEvent()->addEvent("north.");
        }
        return 2; 
    } else if (input == "ne") { 
        if (mode == MOVE) {
            game->getActionEvent()->addEvent("north-east.");
        }
        return 3; 
    } else if (input == "we") { 
        if (mode == MOVE) {
            game->getActionEvent()->addEvent("west.");
        }
        return 4; 
    } else if (input == "ea") { 
        if (mode == MOVE) {
            game->getActionEvent()->addEvent("east.");
        }
        return 5; 
    } else if (input == "sw") { 
        if (mode == MOVE) {
            game->getActionEvent()->addEvent("south-west.");
        }
        return 6; 
    } else if (input == "so") { 
        if (mode == MOVE) {
            game->getActionEvent()->addEvent("south.");
        }
        return 7; 
    } else if (input == "se") { 
        if (mode == MOVE) {
            game->getActionEvent()->addEvent("south-east.");
        }
        return 8; 
    } else { 
        return 0; 
    }
}

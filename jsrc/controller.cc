#include "controller.h"
#include <iostream> //remove after Game implementation and remove couts

using namespace std;

Controller::Controller() {
    game = new Game();

    //TESTING
    cout << "A new Game was created" << endl;
}

Controller::Controller(char filegrid[HEIGHT][WIDTH]) {

//Controller::Controller(char **filegrid) {
    game = new Game(filegrid[HEIGHT][WIDTH]);
    //TESTING
    cout << "A new game with a filegrid was created" << endl;
}

Controller::~Controller() {}

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
    printMenu();
    while (cin >> cmd) {
        if (cmd == "q") {
            //TESTING
            cout << "Game quit" << endl;
            break;
        }

        if (game->getState() == 0) {
            if (cmd == "s") {
                //game->newPlayer(SHADE);
                //TESTING
                cout << "You have created a new Shade" << endl;
                game->setState(1);
            } else if (cmd == "d") {
                //game->newPlayer(DROW);
                //TESTING
                cout << "You have created a new Drow" << endl;
                game->setState(1);
            } else if (cmd == "v") {
                //game->newPlayer(VAMPIRE);
                //TESTING
                cout << "You have created a new Vamp" << endl;
                game->setState(1);
            } else if (cmd == "g") {
                //game->newPlayer(GOBLIN);
                //TESTING
                cout << "You have created a new Goblin" << endl;
                game->setState(1);
            } else if (cmd == "t") {
                //game->newPlayer(TROLL);
                //TESTING
                cout << "You have created a new Troll" << endl;
                game->setState(1);
            } else {
                cout << "That is not a valid menu command" << endl;
            }
        } else if (game->getState() == 1) {
            if (cmd == "r") {
                // restart game
                //TESTING
                cout << "You have surrendered" << endl << "Restarting game..." << endl;
                game->setState(0);
                printMenu();
            } else if (cmd == "u") {
                string input;
                cin >> input;
                if (cin.fail()) {
                    break;
                } else {
                    int dir = direction(input);
                    if (dir != 0) {
                        //Requires Game implementation
                        //game->notify(USE, dir);
                        //TESTING
                        cout << "You attempted to use an item in direction " << dir << endl;
                    } else {
                        badCommand();
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
                        //Requires Game implementation
                        //game->notify(ATTACK, dir);
                        //TESTING
                        cout << "You attempted to attack in direction " << dir << endl;
                    } else {
                        badCommand();
                    }
                }
            } else {
                int dir = direction(cmd);
                if (dir != 0) {
                    //Requires Game implementation
                    //game->notify(MOVE, dir);
                    //TESTING
                    cout << "You attempted to move in direction " << dir << endl;
                } else {
                    badCommand();
                }
            }
        }
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

void printMenu() {
    cout << "Select a race to begin the game, or (q) to quit" << endl;
    cout << "(s)hade, (d)row, (v)ampire, (g)oblin, (t)roll: ";
}

void badCommand() {
    cout << "That is not a valid command" << endl;
}

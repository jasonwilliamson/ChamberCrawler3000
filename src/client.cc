#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include "game.h"
#include "display.h"

using namespace std;

/* direction(c1, c2)
 * returns an integer from 1 - 8 based on the direction created by c1, c2
 * 1  2  3  nw no ne
 * 4     5  we    ea
 * 6  7  8  sw so se
 * returns 0 if c1 and c2 does not create a valid direction
 */
int direction(char c1, char c2) {
    if (c1 == 'n') {
        if (c2 == 'w') { return 1; }
        else if (c2 == 'o') { return 2; }
        else if (c2 == 'e') { return 3; }
    } 
    else if (c1 == 'w' && c2 == 'e') { return 4; }
    else if (c1 == 'e' && c2 == 'a') { return 5; }
    else if (c1 == 's') {
        if (c2 == 'w') { return 6; }
        else if (c2 == 'o') { return 7; }
        else if (c2 == 'e') { return 8; }
    }
    return 0;
}

void set_seed(char* seed_char) {
    string seed_str = seed_char;
    seed_str = seed_str.substr(2);
    istringstream iss(seed_str);
    int seed = 1;
    iss >> seed;
    srand(seed);
}

int main(int argc, char* argv[]) {
    char command;
    Game *game;

    bool seed_set = false, file_set = false;
    if (argc > 1) {
        for (int i = 1; i < argc; i++) {
            if (seed_set == false && argv[i][0] == 's' && argv[i][1] == '=') {
                set_seed(argv[i]);
                seed_set = true;
            } else if (file_set == false) {
                ifstream ifs;
                ifs.open(argv[i]);
                if (ifs.is_open() == false) {
                    cerr << "Error: Specified layout file not found" << endl;
                    return 1;
                }
                ifs.close();
                game = new Game(argv[i]);
                file_set = true;
                cout << "External map loaded" << endl
            }
        }
    } else {
        srand(time(NULL));
        game = new Game();
    }

    while (cin >> command) {
        if (command == 'q') {
            break;
        } else if (command == 'r') {
            game->init();
            game->update();
        } else if (command == 's') {
//            Player* player = new Shade();
//            game->setPlayer(player); //TODO
            game->init();
            game->update();
        } else if (command == 'd') {
            //drow
//            Player* player = new Drow();
//            game->setPlayer(player); //TODO
            game->init();
            game->update();
        } else if (command == 'v') {
            //vampire
//            Player* player = new Vampire();
//            game->setPlayer(player); //TODO
            game->init();
            game->update();
        } else if (command == 'g') {
            //goblin
//            Player* player = new Goblin();
//            game->setPlayer(player); // TODO
            game->init();
            game->update();
        } else if (command == 't') {
            //troll
//            Player* player = new Troll();
//            game->setPlayer(player); //TODO
            game->init();
            game->update();
        } else if (command == 'n' || command == 's' || command == 'e' || command == 'w') {
            char dir;
            cin >> dir;
            if (cin.fail()) {
                break;
            } else {
                //game->movePlayer(direction(command, dir)); //TODO
            }
        } else if (command == 'u') {
            char c1, c2;
            cin >> c1 >> c2;
            if (cin.fail()) {
                break;
            } else {
 //               player.use(direction(c1, c2));
            }
        } else if (command == 'a') {
            char c1, c2;
            cin >> c1 >> c2;
            if (cin.fail()) {
                break;
            } else {
 //               player.attack(direction(c1, c2));
            }
        }
    }
}

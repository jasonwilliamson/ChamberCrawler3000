#include <iostream>

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

int main(int argc, char* argv[]) {
    char command;
    cout << "Welcome to ChamberCrawler 3000!" << endl;
    cout << "Enter a race to begin or q to quit: ";

    while (cin >> command) {
        if (command == 'q') {
            break;
        } else if (command == 'r') {
            //restart game;
        } else if (command == 's') {
            //shade
        } else if (command == 'd') {
            //drow
        } else if (command == 'v') {
            //vampire
        } else if (command == 'g') {
            //goblin
        } else if (command == 't') {
            //troll
        } else if (command == 'n' || command == 's' || command == 'e' || command == 'w') {
            char dir;
            cin >> dir;
            if (cin.fail()) {
                break;
            } else {
 //               player.move(direction(command, dir)); 
                //assuming player.move(int) works the same was as direction
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

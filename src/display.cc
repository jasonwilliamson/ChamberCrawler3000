#include "display.h"

using namespace std;

Display::Display() {
}

Display::~Display() {}

void Display::draw(int state) {
    if (state == -1) {
        cout << "Exiting game" << endl;
    } else if (state == -2) {
        cout << "That is not a valid command" << endl;  
    } else if (state == MENU) {
        cout << endl << endl;
cout << "  ,  /\\  .  " << endl;
cout << " //`-||-'\\\\ " << endl;
cout << "(| -=||=- |)    Welcome to ChamberCrawler 3000!" << endl;
cout << " \\\\,-||-.// " << endl;
cout << "  `  ||  '     " << endl;
cout << "     ||         Select your race:" << endl;
cout << "     ||             - (s)hade" << endl;
cout << "     ||             - (d)row" << endl;
cout << "     ||             - (v)ampire" << endl;
cout << "     ||             - (g)oblin" << endl;
cout << "     ()             - (t)roll" << endl << endl;;
} else if (state == PLAY) {

        for (int r = 0; r < HEIGHT; r++) { 
            for (int c = 0; c < WIDTH; c++) {
                cout << grid[r][c];
            }
            cout << endl;
        }
        cout << "Race: " << race << "    Gold: " << gold << endl;
        cout << "HP: " << hp << endl;
        cout << "ATK: " << atk << endl;
        cout << "DEF: " << def << endl;
        cout << "Action: " << action << endl;
    }
}

void Display::updateMap(int row, int col, char cell) {
    grid[row][col] = cell;
}

void Display::updateCharacter(string race, int gold, int hp, int atk, int def) {
    this->race = race;
    this->gold = gold;
    this->hp = hp;
    this->atk = atk;
    this->def = def;
}

void Display::updateAction(string action) {
    this->action = action;
}

#include <fstream>
#include "display.h"

using namespace std;

Display::Display() {
}

Display::~Display() {}

void Display::draw() {
    for (int r = 0; r < HEIGHT; r++) { 
        for (int c = 0; c < WIDTH; c++) {
            cout << grid[r][c];
        }
        cout << endl;
    }
    cout << "Race: " << " Gold: " << endl;
    cout << "HP: " << endl;
    cout << "ATK: " << endl;
    cout << "DEF: " << endl;
    cout << "Action: " << endl;
}

void Display::setCell(int r, int c, char symbol) {
    grid[r][c] = symbol;
}

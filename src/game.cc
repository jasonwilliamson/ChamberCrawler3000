#include <iostream>
#include <fstream>
#include "game.h"

using namespace std;

Game::Game() {
    floor = new Floor();
    display = new Display();
}

Game::~Game() {
    delete floor;
    delete display;
}

void Game::update() {
    display->draw();
}

void Game::init() {
    ifstream ifs;
    ifs.open("../res/map-layout");
    if (ifs.is_open()) {
        char c;
        ifs >> noskipws;
        for (int h = 0; h < HEIGHT; h++) { 
            for (int w = 0; w < WIDTH; w++) {
                ifs >> c;
                if (ifs.fail()) {
                    break;
                }
                floor->setCell(h, w, c);
                display->setCell(h, w, c);
            }
        }
    }
    ifs.close();
}

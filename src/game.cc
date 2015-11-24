#include <iostream>
#include <fstream>
#include "game.h"
#include "item.h"

using namespace std;

Game::Game() {
    map_file = "../res/map-default";
    floor = new Floor();
    display = new Display();
}

Game::Game(char* custom_map) {
    map_file = custom_map;
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
    generateLayout();
    generatePlayerLocation();
    generateEnemies();
    generatePotions();
    generateGold();
}

void Game::generateLayout() {
    ifstream ifs;
    ifs.open(map_file.c_str());
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

void Game::generatePlayerLocation() {
}

void Game::generateEnemies() {
}

void Game::generatePotions() {
    
}

void Game::generateGold() {

}

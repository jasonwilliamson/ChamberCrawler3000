//
//  filelevel.cpp
//  loadingFromFile
//
//  Created by Jason Williamson on 2015-11-29.
//  Copyright © 2015 Jason Williamson. All rights reserved.
//

#include <iostream>
#include "filelevel.h"
#include "shade.h"
#include "potion.h"
#include "treasure.h"
#include "human.h"
#include "dwarf.h"
#include "elf.h"
#include "orc.h"
#include "merchant.h"
#include "halfling.h"
#include "dragon.h"

using namespace std;

FileLevel::FileLevel(){}

FileLevel::~FileLevel(){}

GameObject* FileLevel::initPlayer(){
    return NULL;
}

GameObject* FileLevel::initPotion(int value, int type){
    GameObject *obj = new Potion(value, type);
    return obj;
}

GameObject* FileLevel::initTreasure(int value, int type){
    GameObject *obj = new Treasure(value, type);
    return obj;
}

GameObject* FileLevel::initEnemy(char race){
    GameObject *obj;
    if (race == 'H') {
        obj = new Human();
    }else if (race == 'W'){
        obj = new Dwarf();
    }else if (race == 'E'){
        obj = new Elf();
    }else if (race == 'O'){
        obj = new Orc();
    }else if (race == 'M'){
        obj = new Orc();
    }else if (race == 'L'){
        obj = new Halfling();
    }else{
        obj = new Dragon();
    }
    return obj;
}

Cell* FileLevel::initLevel(Cell *cellGrid[HEIGHT][WIDTH], char fileMap[HEIGHT][WIDTH]){
    Cell* playerCell;

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            char tile = fileMap[i][j];
            if (tile == '|' || tile == '-' || tile == '+' || tile == '#' ||
                tile == ' ' || tile == '.' || tile == '\\') {
                cellGrid[i][j]->setDefaultChar(tile);
            } else if (tile == '@') {
                playerCell = new Cell(i, j);
                playerCell->setGameObject(tile, initPlayer());
                cellGrid[i][j]->setGameObject(tile, NULL);
                cellGrid[i][j]->setDefaultChar('.');
            } else if (tile == '0' || tile == '1' || tile == '2' ||
                       tile == '3' || tile == '4' || tile == '5') {
                int value;
                if (tile == '0' || tile == '3') {
                    value = 10;
                } else {
                    value = 5;
                }
                cellGrid[i][j]->setGameObject('P', initPotion(value, tile - '0'));
                cellGrid[i][j]->setDefaultChar('.');
            } else if (tile == '6'|| tile == '7' || tile == '8' || tile == '9'){
                int size = 0, type = 0;
                if (tile == '6') {
                    size = 2;
                    type = 0;
                } else if (tile == '7') {
                    size = 1;
                    type = 0;
                } else if (tile == '8') {
                    size = 4;
                    type = 1;
                } else if (tile == '9') {
                    size = 6;
                    type = 2;
                }
                cellGrid[i][j]->setGameObject('G', initTreasure(size, type));
                cellGrid[i][j]->setDefaultChar('.');
            } else if (tile == 'H' || tile == 'W' || tile =='E' || tile == 'O'||
                       tile == 'M' || tile == 'D' || tile == 'L'){
                cellGrid[i][j]->setGameObject(tile, initEnemy(tile));
                cellGrid[i][j]->setDefaultChar('.');
            } else{
                cout << "Error cell value not found!" << endl;
            }
        }
    }
    return playerCell;
}

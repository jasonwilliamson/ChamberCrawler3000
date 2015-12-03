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

using namespace std;
//FileLevel::FileLevel(Floor &floor, CharBoard &cboard):floor(floor), cboard(cboard){}
//FileLevel::FileLevel(Cell *cellGrid[HEIGHT][WIDTH], char *fileMap[HEIGHT][WIDTH]){
//    this->cellGrid[HEIGHT][WIDTH] = cellGrid[HEIGHT][WIDTH];
//}
FileLevel::FileLevel(){}

FileLevel::~FileLevel(){}

GameObject* FileLevel::initPlayer(){
    //initPlayer returns NULL
    return NULL;
}

//TODO remove char val ..not necessary
GameObject* FileLevel::initPotion(char val, int potionType){
    GameObject *obj = new Potion(val, potionType);
    return obj;
}

GameObject* FileLevel::initTreasure(int val, int type){
    cout << "This treasure has value " << val << " filelevel.cc:37"<< endl; //REMOVE
    GameObject *obj = new Treasure(val, type);
    return obj;
}

//add new enemies here...
GameObject* FileLevel::initEnemy(char val){
    GameObject *obj = new Human();
    //switch case probably
    //if (val == 'H') {
    //    obj = new Human()
    //}
    return obj;
}

Cell* FileLevel::initLevel(Cell *cellGrid[HEIGHT][WIDTH], char fileMap[HEIGHT][WIDTH]){
    char playerChar = '@';
    Cell* playerCell;
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            char value = fileMap[i][j];
            if (value == '|' || value == '-' || value == '+' ||
                value == '#' || value == ' ' || value == '.' ||
                value == '\\') {
                cellGrid[i][j]->setDefaultChar(value);
            } else if (value == playerChar) {
                playerCell = new Cell(i, j);
                playerCell->setGameObject(value, initPlayer());
                cellGrid[i][j]->setGameObject(value, NULL);
                cellGrid[i][j]->setDefaultChar('.');
            } else if (value == '0' || value == '1' || value == '2' ||
                       value == '3' || value == '4' || value == '5'){
                int num = value - '0';
                cellGrid[i][j]->setGameObject('P', initPotion(value, num));
                cellGrid[i][j]->setDefaultChar('.');
                //2, 1, 4, 6
            } else if (value == '6'|| value == '7' || value == '8' || value == '9'){
                int size = 0, type = 0;
                if (value == '6') {
                    size = 2;
                    type = 0;
                } else if (value == '7') {
                    size = 1;
                    type = 0;
                } else if (value == '8') {
                    size = 4;
                    type = 1;
                } else if (value == '9') {
                    size = 6;
                    type = 2;
                }
                cellGrid[i][j]->setGameObject('G', initTreasure(size, type));
                cellGrid[i][j]->setDefaultChar('.');
            } else if (value == 'H' || value == 'W' || value =='E' || value == 'O'||
                       value == 'M' || value == 'D' || value == 'L'){
                cellGrid[i][j]->setGameObject(value, initEnemy(value));
                cellGrid[i][j]->setDefaultChar('.');
            } else{
                cout << "Error cell value not found!" << endl;
            }
        }
    }
    return playerCell;
}

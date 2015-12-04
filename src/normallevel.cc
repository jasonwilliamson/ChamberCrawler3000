//
//  normallevel.cpp
//  cc3k
//
//  Created by Jason Williamson on 2015-12-03.
//  Copyright © 2015 Jason Williamson. All rights reserved.
//
#include <cstdlib>
#include <string>
#include <iostream>
#include "normallevel.h"
#include "constants.h"
#include "human.h"
#include "dwarf.h"
#include "elf.h"
#include "orc.h"
#include "merchant.h"
#include "halfling.h"
#include "dragon.h"

using namespace std;

NormalLevel::NormalLevel(){
    chmbrArr.push_back(chmbr1);
    chmbrArr.push_back(chmbr2);
    chmbrArr.push_back(chmbr3);
    chmbrArr.push_back(chmbr4);
    chmbrArr.push_back(chmbr5);
    
}

NormalLevel::~NormalLevel(){}

vector<Cell *> NormalLevel::getChamber(int chamberNumber){
    if (chamberNumber == 1) {
        return chmbr1;
    }else if (chamberNumber == 2){
        return chmbr2;
    }else if (chamberNumber == 3){
        return chmbr3;
    }else if (chamberNumber == 4){
        return chmbr4;
    }else{
        return chmbr5;
    }
}

Cell* NormalLevel::initLevelPlayer(){
    
    //randomly select chamber for player
    int randChamber;
    randChamber = rand() % TOTAL_CHAMBERS;
    vector<Cell *> selChmbr = getChamber(randChamber);
    
    //randomly select place in chamber
    int gridSize = (static_cast<int> (selChmbr.size()));
    int randCell = rand() % gridSize;
    Cell *playerCell = selChmbr[randCell];
    Cell * cell = getRandonChamberCell();
    cell->setGameObject('@', NULL);
    //delete place in chamber so not to duplicate
    selChmbr.erase (selChmbr.begin() + randCell);
    
    //initstairs
    int randStairChamber;
    do{
        randStairChamber = rand() % TOTAL_CHAMBERS;
    }while (randChamber == randStairChamber);
    
    vector<Cell *> stairChmbr = getChamber(randStairChamber);
    gridSize = (static_cast<int> (stairChmbr.size()));
    randCell = rand() % gridSize;
    Cell *stairs = stairChmbr[randCell];
    stairs->setDefaultChar('\\');
    
    //delete place in chamber so not to duplicate
    stairChmbr.erase (stairChmbr.begin() + randCell);
    return playerCell;
}

void NormalLevel::initLevelPotions(){
    int const TOTAL_POTIONS = 10;
    int const POTION_TYPE_COUNT = 6;
    
    //potion spawn
    int potionType = 0;
    for (int i = 0; i < TOTAL_POTIONS; i++) {
        potionType = rand() % POTION_TYPE_COUNT;
        
        //chamber spawn
        Cell *cell = getRandonChamberCell();
        GameObject * potion = new Potion('P', potionType);
        cell->setGameObject('P', potion);
    }
}


void NormalLevel::initLevelTreasure(){
    int const TOTAL_TREASURE = 10;
    int const TREASURE_TYPE_RANGE = 8;
    int const RANGE_TYPE_NORMAL = 5;
    int const RANGE_TYPE_SMALL = 7;
    
    //treasure spawn
    int treasureTyp = 0;
    int randValue = 0;
    for (int i = 0; i < TOTAL_TREASURE; i++) {
        randValue = rand() % TREASURE_TYPE_RANGE + 1;
        if (randValue <= RANGE_TYPE_NORMAL) {
            treasureTyp = 2;
        }else if (randValue <= RANGE_TYPE_SMALL){
            treasureTyp = 1;
        }else{
            treasureTyp = 6;
        }
        
        //chamber spawn
        if (treasureTyp != 6) {
            Cell *cell = getRandonChamberCell();
            GameObject * treasure = new Treasure('G', treasureTyp);
            cell->setGameObject('G', treasure);
        }else{
            // must do this the long way
            int randChamber;
            randChamber = rand() % TOTAL_CHAMBERS;
            vector<Cell *> selChmbr = getChamber(randChamber);
            int gridSize = (static_cast<int> (selChmbr.size()));
            int randCell;
            randCell = rand() % gridSize;
            Cell *cell = selChmbr[randCell];
        
            //delete place in chamber so not to duplicate
            selChmbr.erase (selChmbr.begin() + randCell);
        
            Cell *dragonCell = cell->getEmptyCellForDragon();
            int count = 0;
            for (vector<Cell *>::iterator i = selChmbr.begin(); i != selChmbr.end(); i++) {
                Cell* dp = dynamic_cast<Cell*>(*i);
                if(dp == 0) cout << "dynamic_cast to pointer failed" << endl;
                if (dp == dragonCell) {
                    break;
                }
                ++count;
            }
            if (dragonCell) {
                GameObject * enemy = initEnemy('D');
                dragonCell->setGameObject('D', enemy);
            }
            //erase dragon spot
            selChmbr.erase (selChmbr.begin() + count);
        }
    }
}

//add new enemies here...
//(value == 'H' || value == 'W' || value =='E' || value == 'O'||
//value == 'M' || value == 'D' || value == 'L')
GameObject* NormalLevel::initEnemy(char race){
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
        obj = new Merchant();
    }else if (race == 'L'){
        obj = new Halfling();
    }else{
        obj = new Dragon();
    }
    return obj;
}

void NormalLevel::initLevelEnemy(){
    int const TOTAL_ENEMIES = 20;
    int const ENEMY_TYPE_COUNT = 6;
    char enemyTypes[] = {'H', 'W', 'E', 'O', 'M', 'L'};

    for (int i = 0; i < TOTAL_ENEMIES; i++) {
        int index;
        index = rand() % ENEMY_TYPE_COUNT;
        char val = enemyTypes[index];
        
        Cell *cell = getRandonChamberCell();
        GameObject * enemy = initEnemy(val);
        cell->setGameObject(val, enemy);
    }
}

Cell* NormalLevel::getRandonChamberCell(){
    int randChamber;
    randChamber = rand() % TOTAL_CHAMBERS;
    vector<Cell *> selChmbr = getChamber(randChamber);
    int gridSize = (static_cast<int> (selChmbr.size()));
    int randCell;
    randCell = rand() % gridSize;
    Cell *cell = selChmbr[randCell];
    
    //delete place in chamber so not to duplicate
    selChmbr.erase (selChmbr.begin() + randCell);
    return cell;
}


//make this void
Cell * NormalLevel::initLevel(Cell *cellGrid[HEIGHT][WIDTH], char blankMap[HEIGHT][WIDTH]){
    for (int r = 0; r < HEIGHT; r++) {
        for (int c = 0; c < WIDTH; c++) {
            char value = blankMap[r][c];
            Cell *cell = cellGrid[r][c];
            cell->setDefaultChar(value);
            if (value == '.') {
                if ((r >= 3) && (r <= 6) && (c >= 3) && (c <= 28)) {
                    chmbr1.push_back(cell);
                }else if ((r >= 3) && (r <= 4) && (c >= 39) && (c <= 61)){
                    chmbr2.push_back(cell);
                }else if ((r == 5) && (c >= 39) && (c >= 69)){
                    chmbr2.push_back(cell);
                }else if ((r == 6) && (c >= 39) && (c <= 72)){
                    chmbr2.push_back(cell);
                }else if ((r >= 7) && (r <= 12) && (c >= 61) && (c <= 75)){
                    chmbr2.push_back(cell);
                }else if ((r >= 10) && (r <= 12) && (c >= 38) && (c <= 49)){
                    chmbr3.push_back(cell);
                }else if ((r >= 15) && (r <= 21) && (c >= 4) && (c <= 24)){
                    chmbr4.push_back(cell);
                }else if ((r >= 16) && (r <= 18) && (c >= 65) && (c <= 75)){
                    chmbr5.push_back(cell);
                }else if ((r >= 19) && (r <= 21) && (c >= 37) && (c <= 75)){
                    chmbr5.push_back(cell);
                }
            }
            
        }
    
    }
    
    
    Cell* playerCell;
    Cell *pcell = initLevelPlayer();
    playerCell = new Cell(pcell->getRow(), pcell->getColumn());
    playerCell->setGameObject('@', NULL);
    
    initLevelPotions();
    initLevelTreasure();
    initLevelEnemy();
    return playerCell;
}

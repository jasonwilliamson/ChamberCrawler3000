//
//  filelevel.cpp
//  loadingFromFile
//
//  Created by Jason Williamson on 2015-11-29.
//  Copyright © 2015 Jason Williamson. All rights reserved.
//

#include <iostream>
#include "filelevel.h"
#include "floor.h"
#include "charboard.h"
#include "shade.h"
#include "potion.h"
#include "treasure.h"

using namespace std;
FileLevel::FileLevel(Floor &floor, CharBoard &cboard):floor(floor), cboard(cboard){}

FileLevel::~FileLevel(){}

GameObject* FileLevel::initPlayer(){
    GameObject *obj = new Shade();
    return obj;
}

//TODO remove char val ..not necessary
GameObject* FileLevel::initPotion(char val, int potionType){
    GameObject *obj = new Potion(val, potionType);
    return obj;
}

GameObject* FileLevel::initTreasure(char val, int treasureType){
    GameObject *obj = new Treasure(val, treasureType);
    return obj;
}

void FileLevel::initLevel(){
    char playerChar = '@';
    char stairChar = '\\';
    // default tiles = { - | # + ' ' . }
    char defaultTiles[6] = {'-', '|', '#', '+', ' ', '.'};
    int defaultTileArraySize = 6;
    
    char potionTiles[6] = { '0', '1', '2', '3', '4', '5' };
    int potionTileArraySize = 6;
    char goldTiles[4] = {'6', '7', '8', '9' };
    int goldTileArraySize = 4;
    
    bool valueFound = false;
    
    for (int i = 0; i < cboard.getRows(); i++) {
        for (int j = 0; j < cboard.getColumns(); j++) {
            
            char value = cboard.board[i][j];
            for (int k = 0; k < defaultTileArraySize; k++) {
                if (value == defaultTiles[k]) {
                    
                    floor.setCellNormal(i, j, value);
                    valueFound = true;
                    break;
                }
            }
            if (valueFound) {
                valueFound = false;
                break;
            }
            
            if (value == playerChar) {
                //what if in hallway ..might need game lookup here to make sure tile char is correct
                
                floor.setCellGameObject(i, j, '.', '@', initPlayer());
                break;
            }
            if (value == stairChar) {
                floor.setCellNormal(i, j, '\\');
                break;
            }
            
            //potions = { '0' - RH , '1' - BA, '2'- BD, '3' - PH, 4 - WA, '5' - WD
            // gold = { '6' - normal, '7' - small hoard, '8' - merchant hoard, '9' - dragon hoard
            // enemies 'H' human, 'W' dwarf, 'E' elf, 'O' orc, 'M' merchant, 'D' dragon, 'L' Halfling
            for (int k = 0; k < potionTileArraySize; i++) {
                if (value == potionTiles[k]) {
                    
                    int num = value - '0';
                    floor.setCellGameObject(i, j, '.', 'P', initPotion('P', num));
                    valueFound = true;
                    break;
                }
            }
            
            // skip this value, continue onto next
            if (valueFound) {
                valueFound = false;
                break;
            }
            
            for (int k = 0; k < goldTileArraySize; k++) {
                if (value == goldTiles[k]) {
                    
                    int num = value - '0';
                    floor.setCellGameObject(i, j, '.', 'G', initTreasure('G', num));
                    valueFound = true;
                    break;
                }
            }
            
            cout << "Error cell value not found!" << endl;
        }
    }
}
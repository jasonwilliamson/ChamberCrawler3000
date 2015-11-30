#include "level.h"

void Level::generate(Cell* cells[HEIGHT][WIDTH]) {
    GameObject* curObj;
    for (int r = 0; r < HEIGHT; r++) {
        for (int c = 0; c < WIDTH; c++) {
            int gen = rand() % 6;
            curObj = new GameObject("tile", gen + '0');
            cells[r][c]->setGameObject(curObj);
        }
    }
}

void Level::generate(Cell* cells[HEIGHT][WIDTH], char data[HEIGHT][WIDTH]) {
    GameObject* curObj;
    for (int r = 0; r < HEIGHT; r++) {
        for (int c = 0; c < WIDTH; c++) {
            if (data[r][c] == '|' || data[r][c] == '-' || data[r][c] == '+' || 
                data[r][c] == '#' || data[r][c] == ' ' || data[r][c] == '.' || 
                data[r][c] == '\\') {
                curObj = new GameObject("tile", data[r][c]);
            } else if (data[r][c] == '@') {
                curObj = new Player();
            } else if (data[r][c] == 'H' || data[r][c] == 'W' || 
                data[r][c] == 'E' || data[r][c] == 'O' || data[r][c] == 'M' || 
                data[r][c] == 'D' || data[r][c] == 'L') {
                curObj = new Enemy();
            } else if (data[r][c] == 'P') {
                curObj = new Potion();
            } else if (data[r][c] == 'G') {
                curObj = new Gold(10);
            } else {
                curObj = NULL;
            }
            cells[r][c]->setGameObject(curObj);
        }
    }
}

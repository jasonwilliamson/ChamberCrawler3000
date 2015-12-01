#ifndef GAME_H
#define GAME_H
#include "level.h"
#include "display.h"
#include "cell.h"

class Game {
    Player* player;   
    Display* display;
    Level *levelCreator;
    Cell* cellGrid[HEIGHT][WIDTH];
    Cell* playerCell;
    int gamestate;
    int curFloor;
    bool fromFile;
    char fileMaps[5][HEIGHT][WIDTH];
    void setupCellBlockRadii();

  public:
    Game();
    Game(char data[HEIGHT * 5][WIDTH]);
    ~Game();
    
    void load();
    void nullCells();
    void notify(int mode, int direction);
    int getState();
    void setState(int s);
    Cell* getPlayerCell();
    void setPlayerCell(Cell* c);
    Cell* getCell(int row, int col);
    void setCell(int row, int col, Cell* c);
    Player* getPlayer();
    void setPlayer(int race);
    void setPlayer(Player* p);
};

#endif

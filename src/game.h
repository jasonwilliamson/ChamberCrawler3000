#ifndef GAME_H
#define GAME_H
#include "level.h"
#include "display.h"
#include "cell.h"
#include "enemycatalogue.h"
#include "actionevent.h"
#include "gameobject.h"
#include "player.h"

class Game {
    ActionEvent* actionEvent;
    Player* player;   
    Display* display;
    Level *levelCreator;
    Cell* cellGrid[HEIGHT][WIDTH];
    Cell* playerCell;
    EnemyCatalogue eCatalogue;
    int gamestate;
    int curFloor;
    bool fromFile;
    char fileMaps[5][HEIGHT][WIDTH];
    void setupCellBlockRadii();
    void updateEnemy();
    bool masterTurnFlag;

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

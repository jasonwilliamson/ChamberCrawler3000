#ifndef GAME_H
#define GAME_H
#include "constants.h"
#include "charboard.h"
#include "floor.h"

class Game {
    //Player* player;   
    //Display* display;
    //Level *levelCreator;
    int gamestate;
    CharBoard *boardsArray;
    int currentLevel;
    Floor* floor;
    //char **board;
    
    

  public:
    Game();
    Game(char filemap[HEIGHT][WIDTH]);
    //Game(char **filemap);
    Game(CharBoard *boardsArray);
    ~Game();
    void initLevel();
    
    void notify(int mode, int direction);
    int getState();
    void setState(int s);
//    Player* getPlayer();
//    void setPlayer(Player* p);
    void setPlayer(int race);
};

#endif

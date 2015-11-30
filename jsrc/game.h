#ifndef GAME_H
#define GAME_H
#include "constants.h"
#include "charboard.h"

class Game {
    //Player* player;   
    //Display* display;
    //Level *levelCreator;
    int gamestate;
    CharBoard *boardsArray;
    int currentLevel;
    //char **board;
    
    

  public:
    Game();
    Game(char filemap[HEIGHT][WIDTH]);
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

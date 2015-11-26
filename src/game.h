#ifndef GAME_H
#define GAME_H
#include "constants.h"

class Game {
    //Player* player;   
    //Display* display;
    //Level *levelCreator;
    int gamestate;

  public:
    Game();
    Game(char filemap[HEIGHT][WIDTH]);
    ~Game();
    
    void notify(int mode, int direction);
    int getState();
    void setState(int s);
//    Player* getPlayer();
//    void setPlayer(Player* p);
    void setPlayer(int race);
};

#endif

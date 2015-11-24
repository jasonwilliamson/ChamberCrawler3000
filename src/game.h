#ifndef GAME_H
#define GAME_H
#include "display.h"
#include "floor.h"
#include "constants.h"

// The Game class contains pointers to the Player character, the Display,
// and the Floor layout

class Game {
    //Player player;   
    Display *display;
    Floor *floor;

  public:
    Game();
    ~Game();
    
    void init();
    void update();
};

#endif

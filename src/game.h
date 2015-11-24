#ifndef GAME_H
#define GAME_H
#include "display.h"
#include "floor.h"
#include "constants.h"

// The Game class contains pointers to the Player character, the Display,
// and the Floor layout

class Game {
    //Player* player;   
    Display* display;
    Floor* floor;
    std::string map_file;

  public:
    Game();
    Game(char* custom_map);
    ~Game();
    
    void init();
  //void setPlayer(Player* player);
    void generateLayout();
    void generatePlayerLocation();
    void generateEnemies();
    void generatePotions();
    void generateGold();
    void update();
};

#endif

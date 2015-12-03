#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <string>
#include "constants.h"
#include "game.h"
#include "display.h"

// See controller.cc for documentation

class Controller {
  private:
    Game* game;
    Display* display;

  public:
    Controller();
    Controller(char filegrid[HEIGHT * 5][WIDTH]);
    ~Controller();

    void play();
    void updateDisplay();
    int direction(std::string input);
};


#endif

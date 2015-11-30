#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <string>
#include "constants.h"
#include "game.h"

// See controller.cc for documentation

class Controller {
  private:
    Game* game;

  public:
    Controller();
    Controller(char filegrid[HEIGHT][WIDTH]);
    //Controller(char **filegrid);
    ~Controller();

    void play();
};

int direction(std::string input);
void printMenu();
void badCommand();

#endif

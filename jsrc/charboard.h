/*
 
 Better way to pass 5 char **arrays , this just contains a single char **array 
 this makes it easy to build an array of 5 boards..
 
 */

#ifndef charboard_hpp
#define charboard_hpp
#include "constants.h"

class CharBoard {
private:
    char **board;
    int rows;
    int columns;
    
public:
    CharBoard();
    CharBoard(int rows, int columns);
    ~CharBoard();
};

#endif /* charboard_hpp */

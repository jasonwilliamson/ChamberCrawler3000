/*
 
 Better way to pass 5 char **arrays , this just contains a single char **array 
 this makes it easy to build an array of 5 boards..
 
 */

#ifndef charboard_hpp
#define charboard_hpp
#include "constants.h"

class CharBoard {
private:
    
    int rows;
    int columns;
    
public:
    CharBoard();
    CharBoard(int rows, int columns);
    ~CharBoard();
    char **board;
    int getRows();
    int getColumns();
    //char& operator[](const int nIndex);
};

#endif /* charboard_hpp */

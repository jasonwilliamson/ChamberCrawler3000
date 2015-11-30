//
//  charboard.cc
//  loadingFromFile
//
//  Created by Jason Williamson on 2015-11-28.
//  Copyright © 2015 Jason Williamson. All rights reserved.
//

#include "charboard.h"

CharBoard::CharBoard():rows(HEIGHT), columns(WIDTH){}

//CharBoard::CharBoard(int rows, int columns, char **board):rows(rows), columns(columns),board(board){}
CharBoard(int rows, int columns, char board[HEIGHT][WIDTH]):rows(rows), columns(columns),
    board(board[HEIGHT][WIDTH]){}

CharBoard::~CharBoard(){}

int CharBoard::getRows(){
    return this->rows;
}

int CharBoard::getColumns(){
    return this->columns;
}


//char& CharBoard::operator[](const int nIndex){
//    return *board[nIndex];
//}

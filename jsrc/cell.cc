// ====================================================
// Jason Williamson (20552360)
// David Inglis
// CS 246 Fall 2015
// Assignment 05, CC3K
// File: cell.cc
// ====================================================
//

#include "cell.h"
#include <cstdlib>

//Cell::Cell():row(0), column(0), defaultChar(' '), gameObjectChar(' '){}

Cell::Cell(int row, int column, char defaultChar):
    row(row), column(column), defaultChar(defaultChar), gameObjectChar(' '), gameObj(NULL){}

//Cell::Cell(int row, int column, char defaultChar, char gameObjectChar):
//    row(row), column(column),defaultChar(defaultChar), gameObjectChar(gameObjectChar){}

Cell::Cell(int row, int column, char defaultChar, char gameObjectChar, GameObject* gameObj):
    row(row), column(column),defaultChar(defaultChar), gameObjectChar(gameObjectChar), gameObj(gameObj){}

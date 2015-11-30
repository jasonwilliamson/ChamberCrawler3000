#ifndef FLOOR_H
#define FLOOR_H
#include "constants.h"
#include "cell.h"
#include "gameobject.h"

class Floor {
private:
    //Cell grid[HEIGHT][WIDTH];
    Cell **grid;
    

  public:
    Floor();
    ~Floor();
    
    //void setCell(int row, int col, char defaultSym, char gameObjectSym = ' ');
    /*void setCellwithDefaultSym(int row, int col, char defaultSym);
    void setCellwithGameObjectSym(int row, int col, char defaultSym, char gameObjectSym);
    void setCellGameObject(int row, int col, GameObject *);
    char getCellDefualtChar(int row, int col);
    char getCellGameObjectChar(int row, int col);*/
    
    void setCellNormal(int row, int col, char defaultTile);
    void setCellGameObject(int row, int col, char defaultTile, char gameObjchar, GameObject* gameObj);
    //char getNormalChar();
    //char getGameObjectChar();
    //GameObject* getGameObject();
    //bool hasGameObject();
    
};

#endif

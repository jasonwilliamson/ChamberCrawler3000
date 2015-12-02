// ====================================================
// Jason Williamson (20552360)
// David Inglis
// CS 246 Fall 2015
// Assignment 05, CC3K
// File: gameobject.h
// ====================================================
//

#ifndef gameobject_hpp
#define gameobject_hpp

class GameObject{
  protected:
    bool turnFlag;

  public:
    GameObject();
    virtual ~GameObject();
    bool getTurnFlag();
    void switchTurnFlag();
//    virtual char getDisplayChar() = 0;
};
#endif

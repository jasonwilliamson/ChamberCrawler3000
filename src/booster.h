// ====================================================
// Jason Williamson (20552360)
// David Inglis
// CS 246 Fall 2015
// Assignment 05, CC3K
// File: booster.h
// ====================================================
//

#ifndef booster_hpp
#define booster_hpp

class Booster{
  private:
    int atk;
    int def;

  public:
    Booster();
    Booster(int atk, int def);
    ~Booster();
    void reset();
    void addAtk(int);
    void addDef(int);
    void removeAtk(int);
    void removeDef(int);
    int getAtk();
    int getDef();
};

#endif /* booster_hpp */

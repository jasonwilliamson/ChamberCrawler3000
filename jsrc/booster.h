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
    int attack;
    int defence;
public:
    Booster();
    Booster(int atk, int def);
    ~Booster();
    void reset();
    void setAttack(int);
    void setDefence(int);
    int getAttack();
    int getDefence();
};

#endif /* booster_hpp */

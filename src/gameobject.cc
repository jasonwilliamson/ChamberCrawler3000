// ====================================================
// Jason Williamson (20552360)
// David Inglis
// CS 246 Fall 2015
// Assignment 05, CC3K
// File: gameobject.cc
// ====================================================
//

#include "gameobject.h"

GameObject::GameObject(int value):value(value), turnFlag(false){}

GameObject::~GameObject(){}

bool GameObject::getTurnFlag(){
    return this->turnFlag;
}

void GameObject::switchTurnFlag(){
    this->turnFlag = !this->turnFlag;
}

void GameObject::setValue(int value) {
    this->value = value;
}

int GameObject::getValue() {
    return value;
}

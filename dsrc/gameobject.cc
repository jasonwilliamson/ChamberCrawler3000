#include "gameobject.h"

using namespace std;

GameObject::GameObject(string type, char displayChar) : type(type), displayChar(displayChar) {}

GameObject::~GameObject() {}

string GameObject::getType() { 
    return type;
}

char GameObject::getDisplayChar() {
    return displayChar;
}

void GameObject::setType(std::string type) {
    this->type = type;
}

void GameObject::setDisplayChar(char displayChar) {
    this->displayChar = displayChar;
}

bool GameObject::use() {
    return true;
}

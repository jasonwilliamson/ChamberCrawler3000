#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <string>

class GameObject {
  private:
    std::string type;
    char displayChar;

  public:
    GameObject(std::string type, char displayChar);
    virtual ~GameObject();

    std::string getType();
    char getDisplayChar();
    void setType(std::string type);
    void setDisplayChar(char displayChar);
    virtual bool use();
};

#endif

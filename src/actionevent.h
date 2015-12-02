#ifndef ACTIONEVENT_H
#define ACTIONEVENT_H
#include <string>

class ActionEvent {
    std::string event;

  public:
    ActionEvent();
    ~ActionEvent();
    void setEvent(std::string);
    void addEvent(std::string);
    void clearEvent();
    std::string getEvent();
};

#endif

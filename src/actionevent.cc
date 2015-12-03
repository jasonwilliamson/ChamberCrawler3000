#include <iostream>
#include <string>
#include "actionevent.h"

ActionEvent::ActionEvent() {
}

ActionEvent::~ActionEvent() {}

void ActionEvent::setEvent(std::string e) {
    event = e;
}

void ActionEvent::addEvent(std::string e) {
    event = event + " " + e;
}


void ActionEvent::clearEvent() {
    event = "";
}

std::string ActionEvent::getEvent() {
    return event;
}

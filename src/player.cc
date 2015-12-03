// ====================================================
// Jason Williamson (20552360)
// David Inglis
// CS 246 Fall 2015
// Assignment 05, CC3K
// File: player.cc
// ====================================================
//

#include <iostream>
#include "player.h"

Player::Player(int hp, int atk, int def, std::string race)
    :Character(hp, atk, def), race(race) {
    this->activePotions = new Booster();
}

Player::~Player(){
    delete this->activePotions;
}

std::string Player::getRace() {
    return race;
}

std::string Player::use(Treasure *t) {
    std::string message = "You pick up some gold.";
    addGold(t->getValue());
    return message;
}

std::string Player::use(Potion *p) {
    int type = p->getType();
    std::string message = "You consume the Potion of ";
    std::cout << type << " in potion.cc:35" << std::endl;
    if (type == RH) {
        message += "Restore Health. You feel healthier.";
        setHp(getHp() + p->getValue());
    } else if (type == PH) {
        message += "Poison Health. You feel sick.";
        if (getHp() > p->getValue()) {
            setHp(getHp() - p->getValue());
        }
    } else if (type == BA) {
        message += "Boost Attack. You feel powerful.";
        activePotions->addAtk(p->getValue());
    } else if (type == WA) {
        message += "Wound Attack. You feel weak.";
        activePotions->removeAtk(p->getValue());
    } else if (type == BD) {
        message += "Boost Defence. You feel tough.";
        activePotions->addDef(p->getValue());
    } else if (type == WD) {
        message += "Wound Defence. You feel fragile.";
        activePotions->removeDef(p->getValue());
    }
    return message;
}

int Player::getBoosterAtk() {
    return atk + activePotions->getAtk();
}

int Player::getBoosterDef() {
    return def + activePotions->getDef();
}

void Player::resetBooster() {
    activePotions->reset();
}


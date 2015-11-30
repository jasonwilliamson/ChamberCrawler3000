#include "player.h"

Player::Player() : GameObject("player", '@') {}

Player::~Player() {}

bool Player::use() {
    return true;
}

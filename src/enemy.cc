#include "enemy.h"

Enemy::Enemy() : GameObject("player", 'X') {}

Enemy::~Enemy() {}

bool Enemy::use() {
    return true;
}

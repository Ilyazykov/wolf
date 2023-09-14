#include "character.h"

Character::Character() : pos{0,0}, dir{0,0}, speed{0} {}

Character::Character(const Character& other) {
    this->pos = other.pos;
    this->dir = other.dir;
    this->speed = other.speed;
}

Character::Character(Character&& other) {
    this->pos = std::move(other.pos);
    this->dir = std::move(other.dir);
    this->speed = std::move(other.speed);
}

Character::Character(Position pos, Direction dir, int speed) {
    this->pos = pos;
    this->dir = dir;
    this->speed = speed;
}

Character& Character::operator=(const Character& other) {
    if (this == &other) {
        return *this;
    }

    this->pos = other.pos;
    this->dir = other.dir;
    this->speed = other.speed;

    return *this;
}

Character& Character::operator=(Character&& other) {
    if (this == &other) {
        return *this;
    }

    this->pos = std::move(other.pos);
    this->dir = std::move(other.dir);
    this->speed = std::move(other.speed);

    return *this;
}

Character::~Character() {}
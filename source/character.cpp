#include "character.h"

#include <utility>

Character::Character() : position{0,0}, direction{0,0}, speed{0} {}

Character::Character(const Character& other) {
    this->position = other.position;
    this->direction = other.direction;
    this->speed = other.speed;
}

Character::Character(Character&& other) {
    this->position = std::move(other.position);
    this->direction = std::move(other.direction);
    this->speed = std::move(other.speed);
}

Character::Character(Vec2d position, Vec2d direction, int speed) {
    this->position = position;
    this->direction = direction;
    this->speed = speed;
}

Character& Character::operator=(const Character& other) {
    if (this == &other) {
        return *this;
    }

    this->position = other.position;
    this->direction = other.direction;
    this->speed = other.speed;

    return *this;
}

Character& Character::operator=(Character&& other) {
    if (this == &other) {
        return *this;
    }

    this->position = std::move(other.position);
    this->direction = std::move(other.direction);
    this->speed = std::move(other.speed);

    return *this;
}

Character::~Character() {}
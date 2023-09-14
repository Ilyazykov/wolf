#ifndef CHARACTER_H
#define CHARACTER_H

#include "realCoordinateConverter.h"

class Character {
public:
    Character();
    Character(const Character& other);
    Character(Character&& other);
    
    Character(Vec2d position, Vec2d direction = {0, 0}, int speed = 0);

    Character& operator=(const Character& other);
    Character& operator=(Character&& other);

    ~Character();

private:
    Vec2d position;
    Vec2d direction;
    int speed;
};

#endif // CHARACTER_H
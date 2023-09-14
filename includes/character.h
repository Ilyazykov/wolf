#ifndef CHARACTER_H
#define CHARACTER_H

#include <utility>

struct Position {
    int x;
    int y;
};

struct Direction {
    int dx;
    int dy;
};

class Character {
public:
    Character();
    Character(const Character& other);
    Character(Character&& other);
    
    Character(Position pos, Direction dir = {0, 0}, int speed = 0);

    Character& operator=(const Character& other);
    Character& operator=(Character&& other);

    ~Character();

private:
    Position pos;
    Direction dir;
    int speed;
};

#endif // CHARACTER_H
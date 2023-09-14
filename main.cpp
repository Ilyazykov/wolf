#include <iostream>

#include "map.h"
#include "character.h"
#include "config.h"

int main() {
    Map map("maps/1.map");
    Character ch({1,1}, {0,1}, 0);

    std::cout << map << std::endl;

    return 0;
}
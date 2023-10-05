#ifndef CONFIG_H
#define CONFIG_H

#include <string>
#include <cmath>

const char MAP_TILE_WALL = '#';
const char MAP_TILE_CHARACTER = 'c';
const char MAP_TILE_SPACE = '_';

const int SCALE = 40; // TODO: understand how scale affects the height of walls and remove this dependence

const std::string WINDOW_NAME = "Wolf";

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;
const double WINDOW_ANGLE = M_PI/2;
const double WINDOW_DISTANCE_FROM_CAMERA = 10;

const int WALL_HEIGHT = WINDOW_HEIGHT;

#endif // CONFIG_H
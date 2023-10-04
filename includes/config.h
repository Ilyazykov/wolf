#ifndef CONFIG_H
#define CONFIG_H

#include <string>
#include <cmath>

const char MAP_TILE_WALL = '#';
const char MAP_TILE_CHARACTER = 'c';
const char MAP_TILE_SPACE = '_';

const int SCALE = 60;

const std::string WINDOW_NAME = "Wolf";

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;
const double WINDOW_ANGLE = M_PI/2;
const double WINDOW_DISTANCE_FROM_CAMERA = 10;

#endif // CONFIG_H
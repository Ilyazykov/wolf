#include "camera.h"

#include <utility>

Camera::Camera() : position{0,0}, direction{0,0}, speed{0} {}

Camera::Camera(const Camera& other) {
    this->position = other.position;
    this->direction = other.direction;
    this->speed = other.speed;
}

Camera::Camera(Camera&& other) {
    this->position = std::move(other.position);
    this->direction = std::move(other.direction);
    this->speed = std::move(other.speed);
}

Camera::Camera(Vec2d<double> position, Vec2d<double> direction, int speed) {
    this->position = position;
    this->direction = direction;
    this->speed = speed;
}

Camera& Camera::operator=(const Camera& other) {
    if (this == &other) {
        return *this;
    }

    this->position = other.position;
    this->direction = other.direction;
    this->speed = other.speed;

    return *this;
}

Camera& Camera::operator=(Camera&& other) {
    if (this == &other) {
        return *this;
    }

    this->position = std::move(other.position);
    this->direction = std::move(other.direction);
    this->speed = std::move(other.speed);

    return *this;
}

Camera::~Camera() {}

std::vector<Vec2d<double>> Camera::getScreenPointCoords() const {
    std::vector<Vec2d<double>> res;
    
    double x_center = (position.x + direction.x * WINDOW_DISTANCE_FROM_CAMERA);
    double y_center = (position.y + direction.y * WINDOW_DISTANCE_FROM_CAMERA);

    double half_screen_width = WINDOW_DISTANCE_FROM_CAMERA * std::tan(WINDOW_ANGLE/2);

    double x_first_screen_point = x_center - ( direction.y) * half_screen_width;
    double y_first_screen_point = y_center - (-direction.x) * half_screen_width;

    double x_last_screen_point = x_center + ( direction.y) * half_screen_width;
    double y_last_screen_point = y_center + (-direction.x) * half_screen_width;

    double x_step = (x_last_screen_point - x_first_screen_point) / (WINDOW_WIDTH-1);
    double y_step = (y_last_screen_point - y_first_screen_point) / (WINDOW_WIDTH-1);

    double x = x_first_screen_point;
    double y = y_first_screen_point;
    for (int i = 0; i < WINDOW_WIDTH; ++i) {
        res.push_back({x, y});

        x += x_step;
        y += y_step;
    }

    return res; // TODO: check of extra copy constructor for Vec2d (not should) 
}

std::vector<Vec2d<double>> Camera::getIntersectionPointCoords(const Map& map) const {
    std::vector<Vec2d<double>> res;

    std::vector<Vec2d<double>> screenPointCoords = getScreenPointCoords();

    for (Vec2d<double> onScreenCoord : screenPointCoords ) {
        res.push_back(getIntersectionPointCoord(onScreenCoord, map));
    }

    return res;
}

Vec2d<double> Camera::getIntersectionPointCoord(const Vec2d<double>& onScreenCoord, const Map& map) const {
    Vec2d<double> res;

    Vec2d<int> camera_map_coord = RealCoordinateConverter::toMapCoordinate(position);
    
    if (onScreenCoord.x > position.x) { // TODO: fix bug
        int nearest_map_x = camera_map_coord.x + 1;

        for (int map_x = nearest_map_x; map_x < map.getWidth(); ++map_x) {
            double real_x = RealCoordinateConverter::toLeftSideRealXCoordinate(map_x);
            double real_y = ((real_x - position.x) * onScreenCoord.y / onScreenCoord.x) + position.y;

            Vec2d<int> map_coords = RealCoordinateConverter::toMapCoordinate({static_cast<int>(real_x), static_cast<int>(real_y)});
            if (map.getValue(map_coords.x, map_coords.y) == MAP_TILE_WALL) {
                res = {real_x, real_y};
                break;
            }
        }
    } else {
        int nearest_map_x = camera_map_coord.x;
        
        for (int map_x = nearest_map_x; map_x >= 0; --map_x) {
            double real_x = RealCoordinateConverter::toRightSideRealXCoordinate(map_x);
            double real_y = ((real_x - position.x) * onScreenCoord.y / onScreenCoord.x) + position.y;

            Vec2d<int> map_coords = RealCoordinateConverter::toMapCoordinate({static_cast<int>(real_x), static_cast<int>(real_y)});
            if (map.getValue(map_coords.x, map_coords.y) == MAP_TILE_WALL) {
                res = {real_x, real_y};
                break;
            }
        }
    }

    if (onScreenCoord.y > position.y) {
        int nearest_map_y = camera_map_coord.y + 1;

        for (int map_y = nearest_map_y; map_y < map.getHeight(); ++map_y) {
            double real_y = RealCoordinateConverter::toTopSideRealYCoordinate(map_y);
            double real_x = ((real_y - position.y) * onScreenCoord.x / onScreenCoord.y) + position.x;

            Vec2d<int> map_coords = RealCoordinateConverter::toMapCoordinate({static_cast<int>(real_x), static_cast<int>(real_y)});
            if (map.getValue(map_coords.x, map_coords.y) == MAP_TILE_WALL) {
                if (real_y < res.y) {
                    res = {real_x, real_y};
                }
                break;
            }
        }
    } else {
        int nearest_map_y = camera_map_coord.y;
        
        for (int map_y = nearest_map_y; map_y >= 0; --map_y) {
            double real_y = RealCoordinateConverter::toBottomSideRealYCoordinate(map_y);
            double real_x = ((real_y - position.y) * onScreenCoord.x / onScreenCoord.y) + position.x;

            Vec2d<int> map_coords = RealCoordinateConverter::toMapCoordinate({static_cast<int>(real_x), static_cast<int>(real_y)});
            if (map.getValue(map_coords.x, map_coords.y) == MAP_TILE_WALL) {
                if (real_y > res.y) {
                    res = {real_x, real_y};
                }
                break;
            }
        }
    }

    return res;
}

Vec2d<double> Camera::getPosition() const {
    return position;
}
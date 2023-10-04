#ifndef CHARACTER_H
#define CHARACTER_H

#include "realCoordinateConverter.h"

class Camera {
public:
    Camera();
    Camera(const Camera& other);
    Camera(Camera&& other);
    
    Camera(Vec2d<double> position, Vec2d<double> direction = {0.0, 0.0}, int speed = 0);

    Camera& operator=(const Camera& other);
    Camera& operator=(Camera&& other);

    ~Camera();

public: // TODO change to private
    Vec2d<double> position;
    Vec2d<double> direction;
    int speed;
};

#endif // CHARACTER_H
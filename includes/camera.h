#ifndef CHARACTER_H
#define CHARACTER_H

#include "realCoordinateConverter.h"
#include "config.h"
#include "map.h"

class Camera {
public:
    Camera();
    Camera(const Camera& other);
    Camera(Camera&& other);
    
    Camera(Vec2d<double> position, Vec2d<double> direction = {0.0, 0.0}, int speed = 0);

    Camera& operator=(const Camera& other);
    Camera& operator=(Camera&& other);

    Vec2d<double> getPosition() const;

    std::vector<Vec2d<double>> getScreenPointCoords() const;
    std::vector<Vec2d<double>> getIntersectionPointCoords(const Map& map) const;

    ~Camera();

private:
    Vec2d<double> getIntersectionPointCoord(const Vec2d<double>& onScreenCoord, const Map& map) const;

    Vec2d<double> position;
    Vec2d<double> direction;
    int speed;
};

#endif // CHARACTER_H
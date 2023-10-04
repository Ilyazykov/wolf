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
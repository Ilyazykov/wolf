#ifndef MAP_PAINTER_H
#define MAP_PAINTER_H

#include <iostream>

#include <SFML/Graphics.hpp>

#include "camera.h"
#include "config.h"
#include "map.h"

namespace MapPainter {

    class Painter {
    public:
        Painter() = default;
        virtual void paint(const Map& map, const Camera& camera) = 0;
        
        virtual ~Painter() = default;
    };


    class Stdout : public Painter {
    public:
        Stdout() = default;
        virtual void paint(const Map& map, const Camera& camera);
    };

    class SFML : public Painter {
        std::vector<Vec2d<double>> getScreenPointCoords(const Camera& camera) {
            std::vector<Vec2d<double>> res;
            // camera forward line:
            // x = (position.x) + (direction.x) * t
            // y = (position.y) + (direction.y) * t

            // screen line:
            // x = (position.x + direction.x * WINDOW_DISTANCE_FROM_CAMERA) + ( direction.y) * t
            // y = (position.y + direction.y * WINDOW_DISTANCE_FROM_CAMERA) + (-direction.x) * t

            // first screen point coord:
            double dist = WINDOW_DISTANCE_FROM_CAMERA * std::tan(WINDOW_ANGLE/2);
            double x_first = (camera.position.x + camera.direction.x * WINDOW_DISTANCE_FROM_CAMERA) + ( camera.direction.y) * (-dist);
            double y_first = (camera.position.y + camera.direction.y * WINDOW_DISTANCE_FROM_CAMERA) + (-camera.direction.x) * (-dist);

            // last screen point coord:
            // double dist = WINDOW_DISTANCE_FROM_CAMERA * std::tan(WINDOW_ANGLE/2);
            double x_last = (camera.position.x + camera.direction.x * WINDOW_DISTANCE_FROM_CAMERA) + ( camera.direction.y) * dist;
            double y_last = (camera.position.y + camera.direction.y * WINDOW_DISTANCE_FROM_CAMERA) + (-camera.direction.x) * dist;

            // step:
            double x_step = (x_last - x_first) / (WINDOW_WIDTH-1);
            double y_step = (y_last - y_first) / (WINDOW_WIDTH-1);

            double x = x_first;
            double y = y_first;
            for (int i = 0; i < WINDOW_WIDTH; ++i) {
                res.push_back({x, y});

                x += x_step;
                y += y_step;
            }

            return res; // TODO: check of extra copy constructor for Vec2d (not should) 
        }

        std::vector<Vec2d<double>> getIntersectionPointCoords(Vec2d<double> cameraCoord, Vec2d<double> onScreenCoord, Map map) {
            // TODO
        }
    
    public:
        SFML() = default;
        virtual void paint(const Map& map, const Camera& camera);
    };

    class RayCasting : public Painter {
    public:
        RayCasting() = default;
        virtual void paint(const Map& map, const Camera& camera) {
            // TODO
        }
    };
}

#endif // MAP_PAINTER_H
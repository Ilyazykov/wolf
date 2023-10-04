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

        Vec2d<double> getIntersectionPointCoord(const Vec2d<double>& cameraCoord, const Vec2d<double>& onScreenCoord, const Map& map)
        {
            Vec2d<double> res;

            Vec2d<int> camera_map_coord = RealCoordinateConverter::toMapCoordinate(cameraCoord);
            
            if (onScreenCoord.x > cameraCoord.x) { // TODO: fix buga
                int nearest_map_x = camera_map_coord.x + 1;

                for (int map_x = nearest_map_x; map_x < map.getWidth(); ++map_x) {
                    double real_x = RealCoordinateConverter::toLeftSideRealXCoordinate(map_x);
                    double real_y = ((real_x - cameraCoord.x) * onScreenCoord.y / onScreenCoord.x) + cameraCoord.y;

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
                    double real_y = ((real_x - cameraCoord.x) * onScreenCoord.y / onScreenCoord.x) + cameraCoord.y;

                    Vec2d<int> map_coords = RealCoordinateConverter::toMapCoordinate({static_cast<int>(real_x), static_cast<int>(real_y)});
                    if (map.getValue(map_coords.x, map_coords.y) == MAP_TILE_WALL) {
                        res = {real_x, real_y};
                        break;
                    }
                }
            }

            if (onScreenCoord.y > cameraCoord.y) {
                int nearest_map_y = camera_map_coord.y + 1;

                for (int map_y = nearest_map_y; map_y < map.getHeight(); ++map_y) {
                    double real_y = RealCoordinateConverter::toTopSideRealYCoordinate(map_y);
                    double real_x = ((real_y - cameraCoord.y) * onScreenCoord.x / onScreenCoord.y) + cameraCoord.x;

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
                    double real_x = ((real_y - cameraCoord.y) * onScreenCoord.x / onScreenCoord.y) + cameraCoord.x;

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

        std::vector<Vec2d<double>> getIntersectionPointCoords(const Camera& camera, const Map& map) {
            std::vector<Vec2d<double>> res;

            std::vector<Vec2d<double>> screenPointCoords = getScreenPointCoords(camera);

            for (Vec2d<double> onScreenCoord : screenPointCoords ) {
                res.push_back(getIntersectionPointCoord(camera.position, onScreenCoord, map));
            }

            return res;
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
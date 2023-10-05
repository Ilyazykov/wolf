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
        virtual void paint(const Map& map, const Camera& camera) const = 0;
        
        virtual ~Painter() = default;
    };


    class Stdout : public Painter {
    public:
        Stdout() = default;
        virtual void paint(const Map& map, const Camera& camera) const;
    };

    class SFML : public Painter {
    public:
        SFML() = default;
        virtual void paint(const Map& map, const Camera& camera) const;
    };

    class RayCasting : public Painter {
    public:
        RayCasting() = default;
        virtual void paint(const Map& map, const Camera& camera) const;
    };
}

#endif // MAP_PAINTER_H
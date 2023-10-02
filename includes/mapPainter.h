#ifndef MAP_PAINTER_H
#define MAP_PAINTER_H

#include "map.h"

namespace MapPainter {

    class Painter {
    public:
        Painter() = default;
        virtual void paint(const Map& map) = 0;
        
        virtual ~Painter() = default;
    };


    class Stdout : public Painter {
    public:
        Stdout() = default;
        virtual void paint(const Map& map);
    };

    class SFML : public Painter {
    public:
        SFML() = default;
        virtual void paint(const Map& map);
    };
}

#endif // MAP_PAINTER_H
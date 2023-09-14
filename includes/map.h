#ifndef MAP_H
#define MAP_H

class Map {
public:
    Map(int width, int height);
    Map(const std::string& mapfilePath);

    friend std::ostream& operator<<(std::ostream& os, const Map& map);

private:
    std::vector<std::vector<int>> cells;
};

#endif // MAP_H

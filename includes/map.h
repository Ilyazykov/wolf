#ifndef MAP_H
#define MAP_H

#include <vector>

class Map {
public:
    Map() = delete;
    Map(const Map& other);
    Map(Map&& another) noexcept;

    Map(int width, int height);
    explicit Map(const std::string& mapfilePath);

    Map& operator=(Map&& another) noexcept;
    Map& operator=(const Map& other);

    ~Map();

    friend std::ostream& operator<<(std::ostream& os, const Map& map);

private:
    std::vector<std::vector<char>> cells;
};

#endif // MAP_H

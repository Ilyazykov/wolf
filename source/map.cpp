#include <fstream>
#include <sstream>

#include "map.h"
#include "config.h"

Map::Map(const Map& other) {
    this->cells = other.cells;
}

Map::Map(Map&& other) noexcept {
    this->cells = std::move(other.cells);
}

Map::Map(int width, int height) : cells(height, std::vector<char>(width, '0')) {}

Map::Map(const std::string& mapfilePath) {
    std::ifstream file(mapfilePath);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file: " + mapfilePath);
    }

    cells.clear();
    unsigned int width = 0;

    std::string line;
    while (std::getline(file, line)) {
        std::vector<char> row;
        std::istringstream iss(line);
        char value;
        while (iss >> value) {
            row.push_back(value);
        }

        if ((row.size() != width && width != 0) || row.size() == 0) {
            throw std::runtime_error("Wrong map file format: " + mapfilePath);
        }

        width = row.size();
        cells.emplace_back(std::move(row));
    }
}

char Map::getValue(int x, int y) const {
    if (static_cast<std::vector<char>::size_type>(y) >= cells.size() || 
        static_cast<std::vector<char>::size_type>(y) < 0 ||
        static_cast<std::vector<char>::size_type>(x) >= cells[y].size() ||
        static_cast<std::vector<char>::size_type>(x) < 0
       )
    {
        return MAP_TILE_WALL;
    }
    return cells[y][x];
}

int Map::getWidth() const {
    return cells.at(0).size();
}

int Map::getHeight() const {
    return cells.size();
}

std::ostream& operator<<(std::ostream& os, const Map& map) {
    for (auto& row : map.cells) {
        for (char cell : row) {
            os << cell << ' ';
        }
        os << std::endl;
    }

    return os;
}

Map& Map::operator=(Map&& other) noexcept {
    if (this == &other) {
        return *this;
    }

    this->cells = std::move(other.cells);
    return *this;
}

Map& Map::operator=(const Map& other) {
    if (this == &other) {
        return *this;
    }

    this->cells = other.cells;
    return *this;
}

Map::~Map() {}
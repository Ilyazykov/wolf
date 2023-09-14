#include <vector>
#include <fstream>
#include <sstream>

#include "map.h"

Map::Map(const std::string& mapfilePath) {
    std::ifstream file(mapfilePath);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file: " + mapfilePath);
    }

    cells.clear();

    std::string line;
    while (std::getline(file, line)) {
        std::vector<int> row;
        std::istringstream iss(line);
        int value;
        while (iss >> value) {
            row.push_back(value);
        }
        cells.push_back(row);
    }
}

std::ostream& operator<<(std::ostream& os, const Map& map) {
    for (auto& row : map.cells) {
        for (int cell : row) {
            os << cell << ' ';
        }
        os << std::endl;
    }

    return os;
}
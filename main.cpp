#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

class Map {
public:
    Map(int width, int height) : cells(height, std::vector<int>(width, 0)) {}

    Map(const std::string& mapfilePath) {
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

    friend std::ostream& operator<<(std::ostream& os, const Map& map) {
        for (auto& row : map.cells) {
            for (int cell : row) {
                os << cell << ' ';
            }
            os << std::endl;
        }

        return os;
    }

private:
    std::vector<std::vector<int>> cells;
};

int main() {
    // Map map(3, 4);
    Map map("1.map");

    std::cout << map << std::endl;

    return 0;
}
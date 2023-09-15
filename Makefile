CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra
LDFLAGS += -pthread -lsfml-graphics -lsfml-window -lsfml-system

INCLUDES = -I./ -I./includes
SRC_DIR = source
BUILD_DIR = ./build

MAIN_SOURCE = main.cpp
MAIN_OBJECT = $(patsubst %.cpp, $(BUILD_DIR)/%.o, $(MAIN_SOURCE))
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SOURCES))

EXECUTABLE = $(BUILD_DIR)/main

all: $(BUILD_DIR) $(EXECUTABLE)

$(EXECUTABLE): $(MAIN_OBJECT) $(OBJECTS)
	$(CXX) $(LDFLAGS) $(MAIN_OBJECT) $(OBJECTS) -o $(EXECUTABLE)

$(BUILD_DIR)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(OBJECTS):
	$(MAKE) -C source

run: all
	$(EXECUTABLE)

test:
	$(MAKE) -C tests run

clean:
	$(MAKE) -C source clean
	$(MAKE) -C tests clean
	rm -f $(EXECUTABLE) $(OBJECTS)
	rm -rf $(BUILD_DIR)

.PHONY: clean test run
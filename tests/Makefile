CXX = g++
CXXFLAGS += -std=c++17 -Wall -Wextra -pthread -isystem
LDFLAGS += -pthread -lgtest -lgtest_main -lsfml-graphics -lsfml-window -lsfml-system

INCLUDES = -I./ -I../includes
SRC_DIR = ../source
BUILD_DIR = ../build
TEST_BUILD_DIR = $(BUILD_DIR)/tests

TEST_SOURCES = $(wildcard *.cpp)
TEST_OBJECTS = $(patsubst %.cpp, $(TEST_BUILD_DIR)/%.o, $(TEST_SOURCES))
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SOURCES))

EXECUTABLE = $(TEST_BUILD_DIR)/test

all: $(BUILD_DIR) $(TEST_BUILD_DIR) $(EXECUTABLE)

run: all
	$(EXECUTABLE)

$(EXECUTABLE): $(TEST_OBJECTS) $(OBJECTS)
	$(CXX) $(TEST_OBJECTS) $(OBJECTS) -o $(EXECUTABLE) $(LDFLAGS)

$(TEST_BUILD_DIR)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

$(OBJECTS):
	$(MAKE) -C ../source

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(TEST_BUILD_DIR):
	mkdir -p $(TEST_BUILD_DIR)

clean:
	rm -f $(EXECUTABLE) $(TEST_OBJECTS)
	rm -rf $(TEST_BUILD_DIR)

.PHONY: clean
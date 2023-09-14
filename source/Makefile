CXX = g++
CXXFLAGS += -std=c++14 -Wall -Wextra

INCLUDES = -I./ -I../includes
BUILD_DIR = ../build

SOURCES = $(wildcard *.cpp)
OBJECTS = $(patsubst %.cpp, $(BUILD_DIR)/%.o, $(SOURCES))

all: $(BUILD_DIR) $(OBJECTS)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJECTS)

.PHONY: clean test
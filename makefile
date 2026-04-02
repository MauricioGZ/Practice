# Name of the executable
TARGET = main

# Directorios
SRC_DIR = src
INC_DIR = include
BUILD_DIR = build

# Compiler and flags (C++23)
CXX = g++
CXXFLAGS = -Wall -std=c++23 -I$(INC_DIR)

# .cpp files in src/
SRCS = $(wildcard *.cpp) $(wildcard $(SRC_DIR)/*.cpp)
# Generar rutas para los .o dentro de build/
OBJS = $(addprefix $(BUILD_DIR)/, $(notdir $(SRCS:.cpp=.o)))

# Default rule
all: $(BUILD_DIR)/$(TARGET)

# Link
$(BUILD_DIR)/$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile from the root of the project
$(BUILD_DIR)/%.o: %.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile from src/
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# make build folder
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Run
run: all
	./$(BUILD_DIR)/$(TARGET)

# Clean
clean:
	rm -rf $(BUILD_DIR)

.PHONY: all run clean
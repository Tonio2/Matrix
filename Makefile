CXX = g++
CXXFLAGS = -std=c++17 -Iinclude
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = include

SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(SOURCES:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

TARGET = ex00

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean

clean:
	rm -f $(OBJ_DIR)/*.o $(TARGET)

fclean: clean
	rm -f $(TARGET)

re: fclean all

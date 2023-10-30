CXX = g++
CXXFLAGS = -std=c++17 -Iinclude
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = include
TARGET = ex11

SOURCES_FN = Matrix.cpp Vector.cpp $(TARGET).cpp
SOURCES = $(addprefix $(SRC_DIR)/, $(SOURCES_FN))
OBJECTS = $(SOURCES:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@

.PHONY: clean

clean:
	rm -f $(OBJ_DIR)/*.o $(TARGET)

fclean: clean
	rm -f $(TARGET)

re: fclean all

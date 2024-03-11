CXX = g++
CXXFLAGS = -g -std=c++17 -Iinclude
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = include

SOURCES_FN = Matrix.cpp Vector.cpp
SOURCES = $(addprefix $(SRC_DIR)/, $(SOURCES_FN))
DEPENDENCIES = $(SOURCES:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

EXECS = $(basename $(notdir $(wildcard $(SRC_DIR)/ex*.cpp)))

all: $(EXECS)

$(EXECS): %: $(OBJ_DIR)/%.o $(DEPENDENCIES)
	$(CXX) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@

.PHONY: clean

clean:
	rm -f $(OBJ_DIR)/*.o $(EXECS)

fclean: clean
	rm -f $(EXECS)

re: fclean all

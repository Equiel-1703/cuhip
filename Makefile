CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic

SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))

EXECUTABLE = cuhip

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJS) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $(BIN_DIR)/$(EXECUTABLE) $(OBJS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

clean:
	rm -f $(OBJ_DIR)/*.o
	rm -f $(BIN_DIR)/$(EXECUTABLE)


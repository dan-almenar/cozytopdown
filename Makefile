# ------- Makekefile --------
CXX      := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -Iinclude
LDFLAGS  := -lraylib              # <-- link with Raylib
SRC_DIR  := src
OBJ_DIR  := build
TARGET   := build/game            # <-- final binary inside build/

SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))

all: $(TARGET)

$(TARGET): $(OBJS)
		$(CXX) $(OBJS) -o $@ $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
		@mkdir -p $(OBJ_DIR)
			$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean run

clean:
		rm -rf $(OBJ_DIR) $(TARGET)

run: $(TARGET)
		./$(TARGET)
		
# --------------------------

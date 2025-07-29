# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -I/opt/homebrew/include
LDFLAGS = -L/opt/homebrew/lib -lglfw -framework OpenGL

# Target and sources
TARGET = opengl_test
SRC = opengl_test.cpp #factorial.cpp

# Default rule
all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC) $(LDFLAGS)

# Clean rule to delete compiled files
clean:
	rm -f $(TARGET)

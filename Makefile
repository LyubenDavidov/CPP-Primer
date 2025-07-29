# Compiler and flags
CXX = g++

# Usual: remove -I/opt...
CXXFLAGS = -Wall -Wextra -std=c++17 -I/opt/homebrew/include

# Usual: remove LDFLAGS
LDFLAGS = -L/opt/homebrew/lib -lglfw -framework OpenGL

# Target and sources
TARGET = opengl_test
SRC = opengl_test.cpp #factorial.cpp

# Default rule
all: $(TARGET)

# Usual: remove $(LDFLAGS)
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC) $(LDFLAGS)

# Clean rule to delete compiled files
clean:
	rm -f $(TARGET)

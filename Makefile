# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

# Target and sources
TARGET = pointer_to_array
SRC = pointer_to_array.cpp #factorial.cpp

# Default rule
all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

# Clean rule to delete compiled files
clean:
	rm -f $(TARGET)

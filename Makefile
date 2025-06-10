# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

# Target and sources
TARGET = multiply_numbers
SRC = multiply_numbers.cpp

# Default rule
all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

# Clean rule to delete compiled files
clean:
	rm -f $(TARGET)

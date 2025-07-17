# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

# Target and sources
TARGET = exception_handling
SRC = exception_handling.cpp

# Default rule
all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

# Clean rule to delete compiled files
clean:
	rm -f $(TARGET)

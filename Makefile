# # Compiler and flags
# CXX = g++

# # Usual: remove -I/opt...
# CXXFLAGS = -Wall -Wextra -std=c++17 -I/opt/homebrew/include

# # Usual: remove LDFLAGS
# LDFLAGS = -L/opt/homebrew/lib -lglfw -framework OpenGL

# # Target and sources
# TARGET = functions
# SRC = functions.cpp factorial.cpp

# # Default rule
# all: $(TARGET)

# # Usual: remove $(LDFLAGS)
# $(TARGET): $(SRC)
# 	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC) $(LDFLAGS)

# # Clean rule to delete compiled files
# clean:
# 	rm -f $(TARGET)

CXX       := clang++
# xtensor 0.27.x officially wants C++20, so:
CXXFLAGS  := -std=c++20 -O2

TARGET    := load_npy
SRCS      := load_npy.cpp
OBJS      := $(SRCS:.cpp=.o)

# Homebrew global include path (xtensor & xtl headers are under /opt/homebrew/include)
INCLUDES  := -I/opt/homebrew/include

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)



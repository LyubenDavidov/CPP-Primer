CXX       := clang++

# ---------- ROOT (strip any -std=...) ----------
ROOTCFLAGS_RAW := $(shell root-config --cflags)
ROOTCFLAGS     := $(shell printf '%s\n' "$(ROOTCFLAGS_RAW)" | sed -E 's/-std=[^ ]+//g')
ROOTLIBS       := $(shell root-config --libs)

# --- small test ---

# ---------- xtensor + Eigen ----------
INCLUDES  := -I/opt/homebrew/include -I/opt/homebrew/include/eigen3

# ---------- common flags ----------
CXXSTD    := -std=c++20
CXXWARN   := -O2 -Wall -Wextra

# ----- defining NDEBUG with -DNDEBUG in the CXXFLAGS causes all asserts to be disabled -----
CXXFLAGS  := $(CXXSTD) $(CXXWARN) $(ROOTCFLAGS) $(INCLUDES)


TARGET    := functions

# ---- add amzi_fit.cpp here ----
SRCS      := functions.cpp factorial.cpp
OBJS      := $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(ROOTLIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)







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

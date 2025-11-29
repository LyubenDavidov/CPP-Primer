CXX       := clang++

# ---------- ROOT (strip any -std=...) ----------
ROOTCFLAGS_RAW := $(shell root-config --cflags)
ROOTCFLAGS     := $(shell printf '%s\n' "$(ROOTCFLAGS_RAW)" | sed -E 's/-std=[^ ]+//g')
ROOTLIBS       := $(shell root-config --libs)

# ---------- xtensor + Eigen ----------
INCLUDES  := -I/opt/homebrew/include -I/opt/homebrew/include/eigen3

# ---------- matplot++ ----------
MATPLOT_INCLUDE := -I/opt/homebrew/Cellar/matplotplusplus/1.2.2/include
MATPLOT_LIB     := -L/opt/homebrew/lib -lmatplot  # <-- Use the correct path to the lib

# ---------- common flags ----------
CXXSTD    := -std=c++20
CXXWARN   := -O2 -Wall -Wextra

CXXFLAGS  := $(CXXSTD) $(CXXWARN) $(ROOTCFLAGS) $(INCLUDES) $(MATPLOT_INCLUDE)

TARGET    := matplotpp-example

# ---- add amzi_fit.cpp here ----
SRCS      := matplotpp-example.cpp
OBJS      := $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(ROOTLIBS) $(MATPLOT_LIB)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

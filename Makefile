CXX = g++
CXXFLAGS = -std=c++17 -Iinclude
DEBUG_FLAGS = -g -O0 -DDEBUG
SRC = $(wildcard src/*.cpp)
OUT = app

all: $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(OUT)

debug: $(SRC)
	$(CXX) $(CXXFLAGS) $(DEBUG_FLAGS) $(SRC) -o $(OUT)

clean:
	rm -f $(OUT)
CXX = g++
CXXFLAGS = -std=c++17 -Iinclude
SRC = $(wildcard src/*.cpp)
OUT = app

all: $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(OUT)

clean:
	rm -f $(OUT)
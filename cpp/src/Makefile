# default Makefile for this project

#CXX = /usr/local/opt/llvm/bin/clang++
CXX = g++

DEPS_PATH = ${shell pwd}/deps

all: main 

#INCLUDE_PATH = -I./src -I/usr/local/opt/llvm/include -L/usr/local/opt/llvm/lib
INCLUDE_PATH = -I./src 

CXX_FLAGS = -std=c++11 -Wall -O2 -g

# clean all objects files
clean:
	rm -rf build/*

# lint to check code format and style
#lint:

%.o: %.cpp
	@mkdir -p ./build
	$(CXX) $(CXX_FLAGS) -c $< -o build/$@

main: main.o
	$(CXX) $(CXX_FLAGS) $(INCLUDE_PATH) build/$< -o build/main





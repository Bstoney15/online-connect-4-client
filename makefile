# Compiler
CXX=g++

# Compiler flags
CXXFLAGS=-g -Isrc/include

# Source files
SRC=main.cpp game.cpp

# Libraries
LIBS=-Lsrc/lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_ttf

# Output executable
EXEC=main



all:
	rm $(EXEC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(EXEC) $(LIBS) -mconsole
	./main

clean:
	rm main.exe
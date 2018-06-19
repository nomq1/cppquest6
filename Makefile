CXX=clang++-5.0
CPPFLAGS=-std=c++17 

all: Board.o IllegalCoordinateException.o IllegalCharException.o 

Board.o: Board.cpp Board.h
	$(CXX) $(CPPFLAGS) --compile Board.cpp -o Board.o


IllegalCoordinateException.o : IllegalCoordinateException.cpp
	$(CXX) $(CPPFLAGS) --compile IllegalCoordinateException.cpp -o IllegalCoordinateException.o

IllegalCharException.o: IllegalCharException.cpp	
	(CXX) $(CPPFLAGS) --compile IllegalCharException.cpp -o IllegalCharException.o


#Christopher Acciai
#cga4yc
#Lab 103
#Filename: Makefile

CXX = clang++ $(CXXFLAGS)
DEBUG =-Wall -g
CXXFLAGS = -Wall -O2
OFILES = huffmanNode.o huffmandec.o

.SUFFIXES: .o .cpp

wordpuzzle:$(OFILES)
	$(CXX) $(DEBUG) $(OFILES)
clean:
	-rm -f *.o *~ huffmandec

huffmanNode.o: huffmanNode.cpp huffmanNode.h
huffmandec.o: huffmandec.cpp huffmanNode.h

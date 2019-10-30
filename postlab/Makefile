#Christopher Acciai
#cga4yc
#Lab 103
#Filename: Makefile

CXX1 = clang++ $(CXXFLAGS)
CXX2 = clang $(CXXFLAGS)
DEBUG =-Wall -g
CXXFLAGS = -Wall
OFILES1 = huffmanNode.o huffmanenc.o heap.o
OFILES2 = huffmanNode.o huffmandec.o
OFILES3 = linkedlist.o

.SUFFIXES: .o .cpp .c

all: encoder decoder linkedlist

encoder:$(OFILES1)
	$(CXX1) $(DEBUG) $(OFILES1) -o encoder

decoder:$(OFILES2)
	$(CXX1) $(DEBUG) $(OFILES2) -o decoder

linkedlist:$(OFILES3)
	$(CXX2) $(OFILES3) -o linkedlist

clean:
	-rm -f *.o *~ encoder decoder linkedlist

heap.o: heap.cpp heap.h huffmanNode.h
huffmanNode.o: huffmanNode.cpp huffmanNode.h
huffmandec.o: huffmandec.cpp huffmanNode.h
huffmanenc.o: huffmanenc.cpp heap.h huffmanNode.h
linkedlist.o: linkedlist.c

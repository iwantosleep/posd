INC_DIR = include

all: hw3

hw3: mainTerm.o number.o atom.o variable.o
ifeq (${OS}, Windows_NT)
	g++ -o hw3 mainTerm.o number.o atom.o variable.o -lgtest
else
	g++ -o hw3 mainTerm.o number.o atom.o variable.o -lgtest -lpthread
endif

mainTerm.o: mainTerm.cpp utStruct.h utVariable.h term.h struct.h
	g++ -std=gnu++0x -c mainTerm.cpp
number.o: number.h number.cpp
	g++ -std=gnu++0x -c number.cpp
atom.o: atom.h atom.cpp
	g++ -std=gnu++0x -c atom.cpp
variable.o: variable.h variable.cpp
	g++ -std=gnu++0x -c variable.cpp


clean:
ifeq (${OS}, Windows_NT)
	del *.o *.exe
else
	rm -f *.o hw3
endif
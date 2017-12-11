all: hw7

hw7: main.o term.o atom.o list.o struct.o variable.o 
ifeq (${OS}, Windows_NT)
	g++ -o hw7 main.o term.o atom.o list.o struct.o variable.o -lgtest
else
	g++ -o hw7 main.o term.o atom.o list.o struct.o variable.o -lgtest -lpthread
endif
	
main.o: main.cpp number.h variable.h utIterator.h number.h variable.o
	g++ -std=gnu++0x -c main.cpp
	
variable.o:variable.cpp variable.h
	g++ -std=gnu++11 -c variable.cpp
	
term.o:term.cpp term.h
	g++ -std=gnu++11 -c term.cpp
	
atom.o: atom.cpp atom.h variable.h term.h
	g++ -std=gnu++11 -c atom.cpp
	
list.o: list.cpp atom.h variable.h list.h
	g++ -std=gnu++0x -c list.cpp
struct.o:struct.cpp struct.h
	g++ -std=gnu++11 -c struct.cpp


clean:	
ifeq (${OS}, Windows_NT)
	del *.o *.exe
else
	rm -f *.o hw7
endif
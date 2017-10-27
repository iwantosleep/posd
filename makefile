all: hw4

hw4: main.o term.o number.o atom.o variable.o list.o
ifeq (${OS}, Windows_NT)
	g++ -o hw4 main.o term.o number.o atom.o variable.o list.o -lgtest
else
	g++ -o hw4 main.o term.o number.o atom.o variable.o list.o -lgtest -lpthread
endif

main.o: main.cpp utList.h struct.h
	g++ -std=gnu++0x -c main.cpp
term.o: term.h term.cpp
	g++ -std=gnu++0x -c term.cpp
number.o: number.h number.cpp
	g++ -std=gnu++0x -c number.cpp
atom.o: atom.h atom.cpp
	g++ -std=gnu++0x -c atom.cpp
variable.o: variable.h variable.cpp
	g++ -std=gnu++0x -c variable.cpp
list.o: list.h list.cpp
	g++ -std=gnu++0x -c list.cpp

clean:
ifeq (${OS}, Windows_NT)
	del *.o *.exe
else
	rm -f *.o hw4
endif


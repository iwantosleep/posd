all: hw8 shell

hw8: hw.o list.o term.o struct.o  scanner.h  number.h parser.h exp.h
ifeq (${OS}, Windows_NT)
	g++ -o hw8 hw.o list.o term.o struct.o  -lgtest
else
	g++ -o hw8 hw.o list.o term.o struct.o -lgtest -lpthread
	./hw8
	make clean
endif

shell: shell.o term.o struct.o list.o parser.h scanner.h exp.h term.h variable.h iterator.h
ifeq (${OS}, Windows_NT)
	g++ -o shell shell.o struct.o list.o term.o -lgtest
else
	g++ -o shell shell.o struct.o list.o term.o -lgtest -lpthread
endif


shell.o:  shell.cpp term.h variable.h struct.h iterator.h  \
		  list.h scanner.h parser.h \
		  struct.o list.o term.o
	g++ -std=gnu++0x -c shell.cpp
allTestRunAndClean: utAtom utTerm utVariable utStruct utList utScanner utParser utIterator utExp utShell
	./utAtom && ./utTerm && ./utVariable && ./utStruct && ./utList && ./utScanner && ./utParser && ./utIterator && ./utExp && ./utShell
	make clean
hw.o: hw.cpp term.h  variable.h struct.h iterator.h exception.h \
		   list.h scanner.h parser.h expression.h  number.h \
		   struct.o list.o term.o
	g++ -std=gnu++0x -c hw.cpp

term.o: term.cpp term.h variable.h 
	g++ -std=gnu++0x -c term.cpp
	
struct.o:struct.cpp struct.h term.o number.h
		 g++ -std=gnu++0x -c struct.cpp

list.o: list.cpp list.h number.h term.o
		g++ -std=gnu++0x -c list.cpp


clean:	
ifeq (${OS}, Windows_NT)
	del *.o *.exe
else
	rm -f shell *.o ut*[!.h] hw*[!.cpp]
endif
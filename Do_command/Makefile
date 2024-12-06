all: doCommand

doCommand: doCommand.o
	g++ doCommand.o -o doCommand

doCommand.o: doCommand.cpp
	g++  -c doCommand.cpp -o doCommand.o

clean:
	rm -f doCommand.o  doCommand


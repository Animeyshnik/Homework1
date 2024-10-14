CXX = g++
all: project

project: main.o complex.o sorting.o 
	g++ main.o complex.o sorting.o -o project
main.o: project.cpp 
	g++ -c project.cpp -o main.o
complex.o: Complex.cpp  Complex.h
	g++ -c  Complex.cpp -o complex.o
sorting.o: Sorting.cpp Sorting.h  
	g++ -c Sorting.cpp -o sorting.o

clean:
	rm -f project  *.o



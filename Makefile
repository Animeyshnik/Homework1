CXX = g++
all: project

project: main.o complex.o sorting.o 
	g++ main.o complex.o sorting.o -o project
main.o: ./ComplexNum/project.cpp 
	g++ -c ./ComplexNum/project.cpp -o main.o
complex.o: ./ComplexNum/Complex.cpp  ./ComplexNum/Complex.h
	g++ -c  ./ComplexNum/Complex.cpp -o complex.o
sorting.o: ./ComplexNum/Sorting.cpp ./ComplexNum/Sorting.h  
	g++ -c ./ComplexNum/Sorting.cpp -o sorting.o

clean:
	rm -f project  *.o



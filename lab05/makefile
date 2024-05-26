all: lab

lab: main.o flag.o simple.o
	g++ -std=c++17 main.o flag.o simple.o -o lab
	rm *.o

simple.o: simple.cpp
	g++ -std=c++17 -c simple.cpp

flag.o: flag.cpp
	g++ -std=c++17 -c flag.cpp

main.o: main.cpp
	g++ -std=c++17 -c main.cpp

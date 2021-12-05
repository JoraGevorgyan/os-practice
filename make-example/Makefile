all: main

main: main.o calculator.o printer.o
	g++ main.o calculator.o printer.o -o main

main.o: main.cpp calculator.hpp printer.hpp
	g++ -c main.cpp -o main.o

calculator.o: calculator.cpp calculator.hpp
	g++ -c calculator.cpp -o calculator.o

printer.o: printer.cpp printer.hpp
	g++ -c printer.cpp -o printer.o

clean:
	rm *.o && rm main

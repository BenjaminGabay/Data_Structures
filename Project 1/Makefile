# Makefile for Project 1

output.out: driver.o Node221.o List221.o Stack221.o Queue221.o
	g++ -Wall -std=c++11 driver.o Node221.o List221.o Stack221.o Queue221.o -o output.out

Node221.o: Node221.cpp Node221.h
	g++ -Wall -std=c++11 -c Node221.cpp
	
List221.o: List221.cpp List221.h Node221.h
	g++ -Wall -std=c++11 -c List221.cpp
	
Stack221.o: Stack221.cpp Stack221.h List221.h Node221.h
	g++ -Wall -std=c++11 -c Stack221.cpp
	
Queue221.o: Queue221.cpp Queue221.h List221.h Node221.h
	g++ -Wall -std=c++11 -c Queue221.cpp

driver.o: driver.cpp List221.h Stack221.h Queue221.h Node221.h
	g++ -Wall -std=c++11 -c driver.cpp

# -f removes any error messages if the file is not present
clean:
	rm -rf *.o
	rm -f *.out

run:
	./output.out
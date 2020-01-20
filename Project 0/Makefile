# Makefile for Project 0

driver.out: driver.o Country.o Continent.o
	g++ -Wall -std=c++11 driver.o Country.o Continent.o -o driver.out

Country.o: Country.cpp Country.h
	g++ -Wall -std=c++11 -c Country.cpp
	
Continent.o: Continent.cpp Continent.h Country.h
	g++ -Wall -std=c++11 -c Continent.cpp

driver.o: driver.cpp Continent.h Country.h
	g++ -Wall -std=c++11 -c driver.cpp

# -f removes any error messages if the file is not present
clean:
	rm -rf *.o
	rm -f *.out

run:
	./driver.out
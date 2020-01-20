# Makefile for Project 2

output.out: driver.o TicTacNode.o TicTacToe.o TicTacTrie.o
	g++ -Wall -std=c++11 driver.o TicTacNode.o TicTacToe.o TicTacTrie.o -o output.out

TicTacNode.o: TicTacNode.cpp TicTacNode.h
	g++ -Wall -std=c++11 -c TicTacNode.cpp
	
TicTacToe.o: TicTacToe.cpp TicTacToe.h TicTacNode.h
	g++ -Wall -std=c++11 -c TicTacToe.cpp
	
TicTacTrie.o: TicTacTrie.cpp TicTacTrie.h TicTacToe.h TicTacNode.h
	g++ -Wall -std=c++11 -c TicTacTrie.cpp

driver.o: driver.cpp TicTacToe.h TicTacTrie.h TicTacNode.h
	g++ -Wall -std=c++11 -c driver.cpp

# -f removes any error messages if the file is not present
clean:
	rm -rf *.o
	rm -f *.out

#"$(FILE)" allows for command line argument using command
#make run FILE=<file_name>
run:
	./output.out $(FILE)
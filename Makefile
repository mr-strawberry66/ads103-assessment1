default: game linkedlist

game:
	g++ -std=c++17 Task1/*.cpp
	./a.out

linkedlist:
	g++ -std=c++17 Task2/*.cpp
	./a.out

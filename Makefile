# Компилятор
CC=g++

# Стандарт
STD=c++11

.PHONY: all

all: exec clean

exec: main.o
	$(CC) main.o -o exec -lsfml-graphics -lsfml-window -lsfml-system
main.o: main.cpp
	$(CC) -std=$(STD) -c main.cpp
clean:
	rm -rf *.o

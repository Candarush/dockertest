# Компилятор
CC=g++

# Стандарт
STD=c++11

# Opencv
OPENCVINCLUDES = $(shell pkg-config --cflags opencv)
OPENCVLIBS = $(shell pkg-config --libs opencv)

.PHONY: all

all: exec clean

exec: main.o
	$(CC) main.o -o exec -lsfml-graphics -lsfml-window -lsfml-system $(OPENCVLIBS)
main.o: main.cpp
	$(CC) -std=$(STD) $(OPENCVINCLUDES) -c main.cpp
clean:
	rm -rf *.o

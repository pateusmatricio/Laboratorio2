PROG = ./bin/lab2

CC = g++

CPPFLAGS = -Wall -ansi -pedantic -O0 -g -std=c++11

OBJS = ./build/main.o ./build/dado.o ./build/jogo.o ./build/jogador.o

PROG: $(PROG)

$(PROG): CPPFLAGS += -I. -I./include/

$(PROG): $(OBJS)
	$(CC) $^ $(CPPFLAGS) -o $@

./build/main.o: ./src/main.cpp
	$(CC) -c $^ $(CPPFLAGS) -o $@

./build/dado.o: ./src/dado.cpp
	$(CC) -c $^ $(CPPFLAGS) -o $@

./build/jogador.o: ./src/jogador.cpp
	$(CC) -c $^ $(CPPFLAGS) -o $@

./build/jogo.o: ./src/jogo.cpp
	$(CC) -c $^ $(CPPFLAGS) -o $@

clean:
	rm -f core $(PROG) $(OBJS)

dir:
	mkdir -p bin
	mkdir -p build
	mkdir -p include
	mkdir -p src
	mkdir -p doc
	mkdir -p lib
	mkdir -p test

mv:
	mv *.cpp ./src/
	mv *.h ./include/
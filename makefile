main: main.o Peon.o Alfil.o Reina.o Caballo.o Rey.o Movimiento.o Partida.o Pieza.o Torre.o
	g++ main.o Peon.o Alfil.o Reina.o Caballo.o Rey.o Movimiento.o Partida.o Pieza.o Torre.o -o main.out
main.o: main.cpp Peon.cpp Alfil.cpp Reina.cpp Caballo.cpp Rey.cpp Movimiento.cpp Partida.cpp Pieza.cpp Torre.cpp
	g++ -c main.cpp

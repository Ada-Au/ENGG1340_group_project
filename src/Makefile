player.o: player.cpp player.h
	g++ -c player.cpp

start.o: start.cpp start.h
	g++ -c start.cpp

start: start.o player.o
	g++ start.o player.o -o start

clean:
	rm -f start.o player.o
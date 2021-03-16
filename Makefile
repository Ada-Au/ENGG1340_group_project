main:main.o map.o screen.o player.o 
	g++ -o main main.o map.o screen.o player.o 
main.o:src/main.cpp
	g++ -c src/main.cpp -o main.o
map.o:src/map.cpp src/map.h 
	g++ -c src/map.cpp -o map.o 
player.o:src/player.cpp src/player.h
	g++ -c src/player.cpp -o player.o
screen.o:src/screen.cpp src/screen.h map.o player.o
	g++ -c src/screen.cpp -o screen.o map.o player.o
# constants.o:src/constants.cpp src/constants.h
# 	g++ -c src/constants.cpp -o constants.o

clean:
	rm -f map.o main.o player.o screen.o constants.o
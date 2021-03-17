main:main.o map.o screen.o player.o action.o
	g++ -o main main.o map.o screen.o player.o action.o
main.o:src/main.cpp
	g++ -c src/main.cpp -o main.o
map.o:src/map.cpp src/map.h 
	g++ -c src/map.cpp -o map.o 
player.o:src/player.cpp src/player.h
	g++ -c src/player.cpp -o player.o
screen.o:src/screen.cpp src/screen.h 
	g++ -c src/screen.cpp -o screen.o
action.o:src/action.cpp src/action.h 
	g++ -c src/action.cpp -o action.o 

clean:
	rm -f map.o main.o player.o screen.o action.o
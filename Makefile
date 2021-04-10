main.o:src/main.cpp
	g++ -c -pedantic-errors -std=c++11  src/main.cpp -o main.o
things.o:src/things.cpp src/things.h
	g++ -c -pedantic-errors -std=c++11  src/things.cpp -o things.o
backpack.o:src/backpack.cpp src/backpack.h 
	g++ -c -pedantic-errors -std=c++11  src/backpack.cpp -o backpack.o 
player.o:src/player.cpp src/player.h
	g++ -c -pedantic-errors -std=c++11  src/player.cpp -o player.o
homepage.o:src/homepage.cpp src/homepage.h
	g++ -c -pedantic-errors -std=c++11  src/homepage.cpp -o homepage.o
fight.o:src/fight.cpp src/fight.h 
	g++ -c -pedantic-errors -std=c++11  src/fight.cpp -o fight.o 
map.o:src/map.cpp src/map.h 
	g++ -c -pedantic-errors -std=c++11  src/map.cpp -o map.o 
screen.o:src/screen.cpp src/screen.h 
	g++ -c -pedantic-errors -std=c++11  src/screen.cpp -o screen.o
action.o:src/action.cpp src/action.h 
	g++ -c -pedantic-errors -std=c++11  src/action.cpp -o action.o 
setup.o:src/setup.cpp src/setup.h 
	g++ -c -pedantic-errors -std=c++11  src/setup.cpp -o setup.o
npc.o:src/npc.cpp src/npc.h 
	g++ -c -pedantic-errors -std=c++11  src/npc.cpp -o npc.o 


main:main.o things.o backpack.o player.o fight.o map.o homepage.o screen.o action.o setup.o npc.o 
	g++ -o main main.o things.o backpack.o player.o fight.o map.o homepage.o screen.o action.o setup.o npc.o 
	
clean:
	rm -f  main.o things.o backpack.o player.o fight.o map.o homepage.o screen.o action.o setup.o npc.o 

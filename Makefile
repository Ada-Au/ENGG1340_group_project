# main:main.o map.o screen.o player.o action.o setup.o npc.o fight.o backpack.o
# 	g++ -o main main.o map.o screen.o player.o action.o setup.o npc.o fight.o backpack.o
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
setup.o:src/setup.cpp src/setup.h 
	g++ -c src/setup.cpp -o setup.o
npc.o:src/npc.cpp src/npc.h 
	g++ -c src/npc.cpp -o npc.o 
fight.o:src/fight.cpp src/fight.h 
	g++ -c src/fight.cpp -o fight.o 
backpack.o:src/backpack.cpp src/backpack.h 
	g++ -c src/backpack.cpp -o backpack.o 

main:main.o map.o screen.o player.o action.o setup.o npc.o fight.o backpack.o
	g++ -o main main.o map.o screen.o player.o action.o setup.o npc.o fight.o backpack.o
	
clean:
	rm -f map.o main.o player.o screen.o action.o setup.o npc.o fight.o backpack.o

flag = -pedantic-errors -std=c++11

main.o:src/main.cpp
	g++ -c $(flag) src/main.cpp -o main.o
backpack.o:src/backpack.cpp src/backpack.h 
	g++ -c $(flag) src/backpack.cpp -o backpack.o 
player.o:src/player.cpp src/player.h
	g++ -c $(flag) src/player.cpp -o player.o
homepage.o:src/homepage.cpp src/homepage.h
	g++ -c $(flag) src/homepage.cpp -o homepage.o
fight.o:src/fight.cpp src/fight.h 
	g++ -c $(flag) src/fight.cpp -o fight.o 
map.o:src/map.cpp src/map.h 
	g++ -c $(flag) src/map.cpp -o map.o 
screen.o:src/screen.cpp src/screen.h 
	g++ -c $(flag) src/screen.cpp -o screen.o
action.o:src/action.cpp src/action.h 
	g++ -c $(flag) src/action.cpp -o action.o 
setup.o:src/setup.cpp src/setup.h 
	g++ -c $(flag) src/setup.cpp -o setup.o
npc.o:src/npc.cpp src/npc.h 
	g++ -c $(flag) src/npc.cpp -o npc.o 
shop.o:src/shop.cpp src/shop.h
	g++ -c $(flag) src/shop.cpp -o shop.o
main:main.o backpack.o player.o fight.o map.o homepage.o screen.o action.o setup.o npc.o shop.o
	g++ -o main main.o backpack.o player.o fight.o map.o homepage.o screen.o action.o setup.o npc.o shop.o
	
clean:
	rm -f main.o backpack.o player.o fight.o map.o homepage.o screen.o action.o setup.o npc.o 

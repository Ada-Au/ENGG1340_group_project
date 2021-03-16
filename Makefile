main:main.o map.o
	g++ -o main main.o map.o 
main.o:src/main.cpp
	g++ -c src/main.cpp -o main.o
map.o:src/map.cpp src/map.h
	g++ -c src/map.cpp -o map.o

clean:
	rm -f map.o main.o
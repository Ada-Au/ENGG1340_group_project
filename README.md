# What the HELL (temporary)

A roguelike and turn-based RPG game

## Members

Au Wing Yan, Ada (3035783728)<br>
Chau Hiu Man, Humen (3035783716)

## About this game

YOU DIED. Welcome to the Greek underworld!

In this game, you control a dead man who falls into hell with plenty of monsters. Now you must find a way out… or stay trapped and tortured forever.

## Game Rules

1. Enjoy is the first most important :D<br>
2. Turn-based battles with your strategy<br>
3. WASD for movement control<br>
4. When HP goes zero, player dies with permadeath<br>
5. When MP goes zero, player cannot release any magic skills<br>
6. When Energy goes zero, there are random debuffs for the player. (e.g. max. strength & movement speed decrease...)<br>
7. Energy decreases when time passes/ player makes any steps.<br>
8. Players cannot cross special floors. ( except rivers —> slower the speed/ cannot move across unless a boat is equipped<br>

## Features

- Level-up system with points/experience level to upgrade player's ability <br>
- Total 10 levels in the dungeon (hell). Different levels of the dungeon offer a range of difficulty in monsters corresponding with the range of value in treasure.<br>
- Generally, the difficulty in monsters increases with procedurally generated levels of the dungeon.<br>
- Rare treasures could be found in secret places.<br>
- Each level has a different theme and boss. Also, there are 3 floors for each level.<br>
- NO AUTO SAVING and permadeath(i.e. player character loses all health are considered as dead and cannot be used anymore), is included. <br>
- But there is a saving point after defeating the boss for each level.<br>
- The difficulty (or type) of monsters and the rareness of equipment are shown in different colors.<br>
- Possible types of floors: Water (river), mountain, walls, fire, snow, traps.<br>

## How do the features match the requirements

1. **Generation of random game sets or events**

   - Generation of map, monsters, NPCs, and equipment, such as weapons and tools, is random <br>
   - The values of attack, the dodge chance of the player and the damages to the player, etc. are generated randomly according to the ability of the player and the monsters<br>

2. **Data structures for storing game status**
   <br>(array?)

3. **Dynamic memory management**

4. **File input/output**
   - savings are the file input and output. Savings should include the following types of information:<br>
     1. Level of the player<br>
     2. The game progress and X, Y world location of the player<br>
     3. The states (inc. health, MP, and energy) of the player<br>
     4. The ability of players (inc. strength, intelligence, luck, etc.)<br>
     5. The items in the player's backpack (inc. money, weapons, armor, food, special tools like boats, keys)<br>
     6. The seed of the map (confirm the player is on the current floor)<br>
5. **Program codes in multiple files**
   - programs are planned to be divided into:
     - movement of player character
     - states of player character
     - generation of map, monsters and NPCs
     - generation of items
     - random output of the monsters' attack damage/ defense/ dodge according; and the probability of items appearing on map/ sold by special NPC
     - interface of home page
     - interface for battles

## How to run

copy this to bash:

```
make && make clean
./main
```

or

```
g++ -c map.cpp -o map.o
g++ -c mainChar.cpp -o mainChar.o
g++ -c screen.cpp -o screen.o mainChar.o map.o
g++ -c main.cpp -o main.o
g++ -o main main.o map.o mainChar.o screen.o
./main
```
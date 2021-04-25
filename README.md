#  What A HELL
A roguelike and turn-based RPG game

## Members
Au Wing Yan, Ada (3035783728)<br>
Chau Hiu Man, Humen (3035783716)

## About this game
YOU DIED. Welcome to the HEll!

In this game, you control a dead man who falls into hell with plenty of monsters. Now you must find a way out… or stay trapped and tortured forever.

## Game Rules
1. Enjoy is the first most important :D<br>
2. Turn-based battles with your strategy<br>
2. WASD for movement control<br>
3. When HP goes zero, player dies with permadeath<br>
4. When MP or Energy goes zero, player cannot attack in battle<br>
5. When Energy goes zero, there are random punishment for the player. (i.e. player's HP decreases 1 per action)<br>
6. Energy decreases when player makes any steps on map.<br>
7. Game goal: defeat all the bosses and achieve different ending.<br>

## Features
- Level-up system with skill points & experience level to upgrade player's ability <br>
- Total 10 levels in the dungeon (hell). Different levels of the dungeon offer a range of difficulty in monsters corresponding with the range of value in treasure.<br>
- Generally, the difficulty in monsters increases with procedurally generated levels of the dungeon.<br>
- Chests could be found on the map.<br>
- Each level has a different theme and boss. Also, there are 5 floors for each level.<br>
- NO AUTO SAVING and perma-death(i.e. player character loses all health are considered as dead and cannot be used anymore), is included. <br>
- But there is a saving point after defeating the boss for each level.<br>
- Monsters, NPC and chests are shown in different colors.<br>

## How do the features match the requirements
1. **Generation of random game sets or events**
    - Generation of map, monsters, NPCs, and items, such as weapons and armors, is random <br>
    - The attack value of player and the monster's damages to player are generated randomly according to the ability of player and the monsters<br>

2. **Data structures for storing game status**
    - Class Player defines all the status of player, it contains:
        - player's status (inc. mp, hp, energy, maxMp, maxHp, max energy, max Exp, damage, defense, level, game level, and coin)
        - vector of player's buffs and debuffs
        - player x, y coordination
        - player's name, role, gender
    - Structures for items, healing, armor, and weapon, contains:
        - name
        - description
        - functions
        - cost and price
    - Class Map stores in a 2D array for the landscape, generation of the map, and removing icons
    - Vectors to store player's items and shop items
    - Structure to store NPCs information and array of string to store NPCs' figures

3. **Dynamic memory management**
    - array and pointer using in map generation
    - Array for player status, interaction, items

4. **File input/output**
    - savings is file output and loading is file input. Saving includes the following types of information:<br>
        1. Level of the player<br>
        2. The game progress of player<br>
        3. The states (inc. HP, MP and energy...) of the player<br>
        4. The ability of players (inc. damage and defense etc.)<br>
        5. The items in player's backpack (inc. money, weapons, armors, healings)<br>
        6. Player's equipment (player's armor and player's weapon)<br>
5. **Program codes in multiple files**
    - programs are divided into:
        - action.cpp & action.h: movement of player character; interaction of players between monsters, NPC and chests; ending of game 
        - backpack.cpp & backpack.h: generation and storage of items; interface for backpack; interactions between players and backpack
        - fight.cpp & fight.h: interface for battles; deal with player's actions in battle; set up of monsters' ability according to player game progress
        - homepage.cpp & homepage.h: menu for player to save/load/quit game
        - map.cpp & map.h: generation of map, monsters, NPCs and chests; monster's movement
        - npc.cpp & npc.h: render NPC with talk screen; NPCs' ability and figure
        - player.cpp & player.h: status of player character; upgrade of player; add & update buffs/debuffs on player
        - saving.cpp & saving.h: save game and load game (game file is in [player's name].txt); deal with repeat of player's name in creating files
        - screen.cpp & screen.h: render map screen; print player's status on right side of map; help menu; clear screen
        - setup.cpp & setup.h: set up player's information and storyline at beginning
        - shop.cpp & shop.h: render shop screen; generate shop items; deal with player's actions in shop
        - main.cpp: execute file 
## List of Non-standard C/C++ libraries
   - conio.h: 

## Compilation and Execution Instructions
   - Our game are supported in all kinds of operating systems (i.e. Mac, Window, and Linux)
    ** Download & Set up **
   - Open terminal on your PC and go the directory that contains our game
   - In Mac and Linux, you can create our game execute file by typing "make main". In Window, you can create it by typing "./Makefile".
   - In Mac and Linux, you can open our game execute file by typing "./main". In Window, main.exe is created instead of main. Thus, please open our game by typing "./main.exe" in Window.
   - Load game: 

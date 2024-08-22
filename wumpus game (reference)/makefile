CC=g++ -std=c++11 -g
EXE_FILE=run

all: $(EXE_FILE)

$(EXE_FILE): bats.o event.o game.o gold.o room.o stalactites.o wumpus.o player.o main.cpp
	$(CC) bats.o event.o game.o gold.o room.o stalactites.o wumpus.o player.o main.cpp -o $(EXE_FILE)

bats.o: bats.h bats.cpp
	$(CC) -c bats.cpp

event.o: event.h event.cpp
	$(CC) -c event.cpp

game.o: game.h game.cpp
	$(CC) -c game.cpp

gold.o: gold.h gold.cpp
	$(CC) -c gold.cpp

room.o: room.h room.cpp
	$(CC) -c room.cpp

stalactites.o: stalactites.h stalactites.cpp
	$(CC) -c stalactites.cpp

wumpus.o: wumpus.h wumpus.cpp
	$(CC) -c wumpus.cpp

player.o: player.h player.cpp
	$(CC) -c player.cpp

clean:
	rm -f *.o $(EXE_FILE)
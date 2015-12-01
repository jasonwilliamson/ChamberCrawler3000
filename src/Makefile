CXX = g++
CXXFLAGS =  -Wall -g -MMD
EXEC = cc3k
OBJECTS = client.o controller.o game.o cell.o display.o enemy.o gameobject.o gold.o level.o player.o potion.o treasure.o booster.o filelevel.o human.o vampire.o shade.o item.o character.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean
clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}	

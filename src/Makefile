CXX = g++
CXXFLAGS =  -Wall -g -MMD
EXEC = cc3k
OBJECTS = client.o controller.o game.o cell.o display.o enemy.o gameobject.o level.o player.o potion.o treasure.o booster.o filelevel.o human.o vampire.o shade.o item.o character.o enemycatalogue.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean
clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}	

git:
	mv *.o *.d cc3k ../bin/

ungit:
	cp ../bin/* .

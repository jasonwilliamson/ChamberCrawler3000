CXX = g++
CXXFLAGS =  -Wall -g -MMD
EXEC = cc3k
OBJECTS = client.o controller.o game.o cell.o display.o enemy.o gameobject.o level.o player.o potion.o treasure.o booster.o filelevel.o human.o vampire.o shade.o drow.o goblin.o troll.o item.o character.o enemycatalogue.o actionevent.o normallevel.o dragon.o dwarf.o elf.o halfling.o merchant.o orc.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean
clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}	

bin:
	mv *.o *.d cc3k ../bin/

back:
	cp ../bin/* .


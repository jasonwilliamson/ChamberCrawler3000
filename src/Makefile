CXX = g++
CXXFLAGS =  -Wall -g -MMD
EXEC = cc3k
OBJECTS = client.o game.o display.o floor.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean
clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}	

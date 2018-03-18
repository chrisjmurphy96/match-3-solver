#Name: Chris Murphy

CXX = /usr/bin/g++
CXXFLAGS = -g -Wall -W -pedantic-errors

OBJECTS = main.o grid.o action.o treenode.o IDDFTS.o

#Suffix rules
.SUFFIXES: .cpp

.cpp.o: $<
	${CXX} -c ${CXXFLAGS} $< -o $@

default: all

all: main

#Dependencies
main: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o $@

main.o: main.cpp grid.h grid.cpp action.h action.cpp treenode.h treenode.cpp IDDFTS.h IDDFTS.cpp

#grid.o: grid

grid.o: grid.h grid.cpp

action.o: action.h action.cpp

treenode.o: treenode.h treenode.cpp action.h action.cpp grid.h grid.cpp

IDDFTS.o: IDDFTS.h IDDFTS.cpp action.h action.cpp treenode.h treenode.cpp

#Clean targets
clean:
	-@rm core
	-@rm main
	-@rm ${OBJECTS}
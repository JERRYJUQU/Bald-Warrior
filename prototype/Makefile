CXX = g++                   # compiler
CXXFLAGS = -std=c++14 -g -Wall -MMD # compiler flags
OBJECTS = floor.o chamber.o textdisplay.o main.o    # object files for the executable
EXEC = baldwarrior                 # executable name
DEPENDS = ${OBJECTS:.o=.d}  # substitute ".o" with ".d"

########## Targets ##########

.PHONY : all clean          # not file names

${EXEC} : ${OBJECTS}                # link step executable
	${CXX} ${CXXFLAGS} $^ -o $@     # additional object files before $^

-include ${DEPENDS}         # include *.d files containing program dependences

clean :                     # remove files that can be regenerated
	rm -f ${DEPENDS} ${OBJECTS} ${EXEC}

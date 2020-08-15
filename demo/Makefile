CXX = g++                   # compiler
CXXFLAGS = -std=c++14 -g -Wall -MMD -w# compiler flags
CCF = $(wildcard *.cc)
OBJECTS = ${CCF:.cc=.o}   # object files for the executable
EXEC = cc3k                 # executable name
DEPENDS = ${OBJECTS:.o=.d}  # substitute ".o" with ".d"

########## Targets ##########

.PHONY : all clean          # not file names

${EXEC:.cc=.o} : ${OBJECTS}                # link step executable
	${CXX} ${CXXFLAGS} $^ -o $@     # additional object files before $^

-include ${DEPENDS}         # include *.d files containing program dependences

clean :                     # remove files that can be regenerated
	rm -f ${DEPENDS} ${OBJECTS} ${EXEC}

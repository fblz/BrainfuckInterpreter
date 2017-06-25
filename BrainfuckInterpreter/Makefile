CXX=clang++
CXXFLAGS=-std=c++14 -I ./ -ggdb -Wall -Wextra -Wpedantic -Wconversion -Wsign-conversion -c

SOURCEDIR=./

STATLIBS=

PATH := /usr/bin:$(PATH)

LDFLAGS=

SOURCES:= $(shell find $(SOURCEDIR) -name '*.cpp')
OBJDIR=./
OBJ=$(SOURCES:.cpp=.o)
OBJECTS=$(addprefix $(OBJDIR)/,$(SOURCES:.cpp=.o))
EXECUTABLE=myBrainfuckInter

all: $(SOURCES) $(EXECUTABLE)
	@echo Finish!!

$(EXECUTABLE): $(OBJ)
	@echo Build executable $@
	@$(CXX) $(LDFLAGS) $(OBJECTS) $(STATLIBS) -o $@

.cpp.o:
	@echo Build object $@
	@$(CXX) $(CXXFLAGS) $< -o $(OBJDIR)/$@

clean:
	rm -f $(shell find ./ -name '*.o')

distclean:
	#rm -fr build
        #git ls-files --others | xargs rm -rf

run:
	@echo Run executable
	./$(EXECUTABLE)


BINARY := tskSched

SRC := $(wildcard src/*.cpp)
INC := $(wildcard inc/*.h)
OBJ: = ${SRC:.cpp INC:.h=.o}
DEPENDENCIES := ${SRC:.cpp=.d}

CXX := g++

OPTCXXFLAGS = 

# Debugging flags
#DBGCXXFLAGS = -g

WARNFLAGS := -W -Wall -lm
CXXFLAGS := -O0
LDFLAGS := -WALL

$(BINARY) : ${OBJ}
	$(CXX) $(LDFLAGS) -o $@ $^ $(XERCES_LDFLAGS)

# From .pp to .o: Dependency files are generated here
${OBJ}: %.o: %.cpp
	$(CXX) ${CXXFLAGS} -MMD -MF $(subst .o,od,$@) -o $@ -c $<

all: ${BINARY}

clean:
	$(OBJ) $(DEPENDENCIES) $(BINARY)

.PHONY: clean

-include $(DEPENDENCIES)

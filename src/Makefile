CXX=g++
CXXFLAGS=-c -Wall -Wextra -Werror
STD=-std=c++17
TFLAGS=-lgtest -lpthread
TFILE=test.cpp
HEADERS=matrix.h
SOURCES=matrix.cpp
OBJECTS=$(SOURCES:.cpp=.o)
LIB=matrix.a

all: $(LIB)

$(OBJECTS): $(SOURCES) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(STD) $(SOURCES)

$(LIB): $(OBJECTS)
	ar rcs $(LIB) $(OBJECTS)
	rm -rf *.o

test: $(LIB)
	$(CXX) $(TFILE) $(STD) $(TFLAGS) $(LIB) -o test.out
	./test.out

clean:
	rm -rf *.o
	rm -rf *.a
	rm -rf *.out
	
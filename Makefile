CXX=g++
CXXFLAGS=-c -std=c++20
TFLAGS=-lgtest -lpthread
SOURCES=matrix_help.cpp matrix_constructors.cpp matrix_methods.cpp matrix_operators.cpp
HEADERS=matrix_oop.h
OBJECTS=$(SOURCES:.cpp=.o)
LIB=matrix_oop.a

$(OBJECTS): $(SOURCES) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SOURCES)

$(LIB): $(OBJECTS)
	ar rcs $(LIB) $(OBJECTS)

test: clean $(LIB)
	$(CXX) test.cpp -std=c++20 $(TFLAGS) $(LIB) -o test.out
	./test.out

clean:
	rm -rf *.o
	rm -rf *.a
	rm -rf *.out
	rm -rf *.gcno *.info *.gcda
	rm -rf ./report
	rm -rf ./debug.out.dSYM
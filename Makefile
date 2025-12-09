# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -std=c++17

# External libraries (ncurses)
LIBS = -lncurses

# Source files
SRCS = FractionUI.cpp Fractions.cpp
HDRS = Fraction.h

# Targets
EXEC = calculator
TEST_EXEC = test

# Doctest flags (if available)
DOCTEST_FLAGS = -DDOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
DOCTEST_LIB = # If using a doctest library file, add its path here. Otherwise, use the header only.

.PHONY: all run test clean

all: $(EXEC)

$(EXEC): main.o Fraction.o
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LIBS)

main.o: FractionUI.cpp Fraction.h
	$(CXX) $(CXXFLAGS) -c main.cpp

Fraction.o: Fractions.cpp Fraction.h
	$(CXX) $(CXXFLAGS) -c Fractions.cpp

run: $(EXEC)
	./$(EXEC)

test: test.o Fraction.o
	$(CXX) $(CXXFLAGS) $^ -o $(TEST_EXEC)
	./$(TEST_EXEC)

test.o: test_fractions.cpp Fraction.h
	$(CXX) $(CXXFLAGS) $(DOCTEST_FLAGS) -c test_fractions.cpp

clean:
	rm -f *.o $(EXEC) $(TEST_EXEC)
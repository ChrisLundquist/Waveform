#VPATH= src:test
CFLAGS= -Wall -Wextra -pedantic
CXX=g++ $(FLAGS)
TEST_LIBS=-lgtest -lgtest_main

test: test/particle_spec.o test/color_spec.o test/mass_spec.o all
	rm -f ./tests
	$(CXX) test/*.o src/*.o $(TEST_LIBS) -o tests
	./tests

all: src/Particle.o src/Color.o src/Mass.o

.cpp.o:
	$(CXX) -c $(CFLAGS) $< -o $@



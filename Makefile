#VPATH= src:test
CFLAGS= -Wall -Wextra -pedantic
CXX=g++-4.2
TEST_LIBS=-lgtest -lgtest_main
LIBS= -lGLEW
FRAMEWORKS = -framework GLUT -framework OpenGL

test: test/particle_spec.o test/color_spec.o test/mass_spec.o test/actor_spec.o all
	rm -f ./tests
	$(CXX) test/*.o src/*.o $(TEST_LIBS) -o tests
	./tests

all: src/Particle.o src/Color.o src/Mass.o src/Actor.o src/Waveform.o

game: all main.o
	$(CXX) $(FRAMEWORKS) $(LIBS) main.cpp -o Waveform

clean:
	rm -rf src/*o test/*o Waveform

.cpp.o:
	$(CXX) -c $(CFLAGS) $< -o $@



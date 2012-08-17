#VPATH= src:test
CFLAGS= -Wall -Wextra -pedantic
CXX=g++-4.2
TEST_LIBS=-lgtest -lgtest_main
LIBS= -lGLEW
FRAMEWORKS = -framework GLUT -framework OpenGL


test: all model_specs controller_specs view_specs
	rm -f ./tests
	$(CXX) spec/models/*.o src/models/*.o  $(TEST_LIBS) -o tests
	./tests
#spec/controllers/*.o spec/views/*.o src/controllers/*.o src/views/*.o
model_specs: spec/models/particle_spec.o spec/models/color_spec.o spec/models/mass_spec.o spec/models/actor_spec.o spec/models/particle_generator_spec.o

controller_specs:

view_specs:

models: src/models/Particle.o src/models/Color.o src/models/Mass.o src/models/Actor.o src/models/Waveform.o src/models/ParticleGenerator.o

controllers:

views:

all: models controllers views

game: all main.o
	$(CXX) $(FRAMEWORKS) $(LIBS) src/*.o main.cpp -o Waveform

run: game
	./Waveform

clean:
	rm -rf src/models/*.o spec/models/*.o Waveform

.cpp.o:
	$(CXX) -c -O4 $(CFLAGS) $< -o $@



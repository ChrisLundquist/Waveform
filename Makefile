#VPATH= src:test
CFLAGS= -Wall -Wextra -pedantic
CXX=g++-4.2
TEST_LIBS=-lgtest -lgtest_main
LIBS= -lGLEW
FRAMEWORKS = -framework GLUT -framework OpenGL
OBJECT_FILES =  src/models/*.o
OBJECT_SPEC_FILES = spec/models/*.o
#spec/controllers/*.o spec/views/*.o src/controllers/*.o src/views/*.o


test: all model_specs controller_specs view_specs
	rm -f ./tests
	$(CXX) $(OBJECT_FILES) $(OBJECT_SPEC_FILES) $(TEST_LIBS) -o tests
	./tests

model_specs: spec/models/particle_spec.o spec/models/color_spec.o spec/models/mass_spec.o spec/models/actor_spec.o spec/models/particle_generator_spec.o

controller_specs:

view_specs:

models: src/models/Particle.o src/models/Color.o src/models/Mass.o src/models/Actor.o src/models/Waveform.o src/models/ParticleGenerator.o

controllers:

views:

all: models controllers views

game: all main.o
	$(CXX) $(FRAMEWORKS) $(LIBS) $(OBJECT_FILES) main.cpp -o Waveform

run: game
	./Waveform

clean:
	rm -rf src/models/*.o spec/models/*.o Waveform

.cpp.o:
	$(CXX) -c -O4 $(CFLAGS) $< -o $@



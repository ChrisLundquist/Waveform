#VPATH= src:test
CFLAGS= -Wall -Wextra -pedantic
CXX=g++-4.2
TEST_LIBS=-lgtest -lgtest_main
LIBS= -lGLEW
FRAMEWORKS = -framework GLUT -framework OpenGL
OBJECT_FILES =  src/models/*.o src/controllers/*.o
OBJECT_SPEC_FILES = spec/models/*.o spec/controllers/*.o
# spec/views/*.o src/controllers/*.o src/views/*.o


test: all model_specs controller_specs view_specs
	rm -f ./tests
	$(CXX) $(OBJECT_FILES) $(OBJECT_SPEC_FILES) $(TEST_LIBS) -o tests
	./tests

valgrind: test
	valgrind --leak-check=yes ./tests

model_specs: spec/models/particle_spec.o spec/models/color_spec.o spec/models/mass_spec.o spec/models/particle_generator_spec.o

controller_specs: spec/controllers/actor_controller_spec.o spec/controllers/particle_generator_controller_spec.o

view_specs:

models: src/models/particle.o src/models/color.o src/models/mass.o src/models/actor.o src/models/waveform.o src/models/particle_generator.o

controllers: src/controllers/actor_controller.o src/controllers/particle_generator_controller.o

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



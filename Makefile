#VPATH= src:test
CFLAGS= -Wall -Wextra -pedantic
CXX=g++
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

model_specs: spec/models/particle_spec.o spec/models/particle_generator_spec.o spec/models/force_spec.o

controller_specs: spec/controllers/particle_generator_controller_spec.o spec/controllers/force_controller_spec.o

view_specs:

models: src/models/particle.o src/models/actor.o src/models/particle_generator.o src/models/force.o

controllers: src/controllers/particle_generator_controller.o src/controllers/force_controller.o src/controllers/waveform.o

views:

all: models controllers views

game: all main.o
	$(CXX) $(FRAMEWORKS) $(LIBS) $(OBJECT_FILES) main.cpp -o Waveform

run: game
	./Waveform

clean:
	rm -rf $(OBJECT_FILES) $(OBJECT_SPEC_FILES) Waveform

.cpp.o:
	$(CXX) -c -O4 $(CFLAGS) $< -o $@



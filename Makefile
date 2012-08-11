VPATH= src:test
CXX=g++
TEST_LIBS=-lgtest -lgtest_main
TEST_FILES=./test/*.cpp
SOURCE_FILES=./src/*.cpp
OBJECT_FILES=./src/*.o ./test/*.o
FILES = $(TEST_FILES) $(SOURCE_FILES)

all:
	cd src/ && $(CXX) -c *.cpp
	cd test/ && $(CXX) -c *.cpp

test: all
	rm -f ./tests
	$(CXX) $(OBJECT_FILES) $(TEST_LIBS) -o tests
	./tests


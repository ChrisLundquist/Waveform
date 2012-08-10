CXX=g++
TEST_LIBS=-lgtest -lgtest_main

all:

test:
	$(CXX) ./test/*.c* $(TEST_LIBS) -o tests
	./tests
.PHONY: test

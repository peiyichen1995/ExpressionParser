CXXFLAGS = -Wall -g -Iinclude
CXX=g++

src = $(wildcard src/*.cpp)
obj = $(src:.cpp=.o)

ExpressionParser: $(obj)
	$(CXX) -g -o $@ $^

.PHONY: clean

clean:
	rm -f src/*.o

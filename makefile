bindir=./bin
srcdir=./src
objdir=./obj
libdir=./lib
incdir=./include

target=main
src=$(shell find . -name "*.cpp")
#src=$(wildcard $(srcdir)/*.cpp)
obj=$(patsubst %.cpp, %.o, $(src))
lib=$(notdir $(shell find $(libdir) -name "*.so"))pthread

CXX=g++
CXXFLAGS=-std=c++11 -g -O3 -Wall 
CXXLIB=-I$(incdir) -L$(libdir) -l$(lib)

$(target):$(obj)
	$(CXX) $(CXXFLAGS) $(CXXLIB) -o $@ $^

%.o:%.cpp
	$(CXX) -c $(CXXFLAGS) $< -o $@

echo:
	@echo $(target)
	@echo $(obj)
	@echo $(src)
	@echo $(CXXLIB)

clean:
	rm $(obj) $(target) -f



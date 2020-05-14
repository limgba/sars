srcdir=./src
libdir=./lib
incdir=./include

target=main.out
src=$(shell find $(srcdir) -name "*.cpp")
obj=$(patsubst %.cpp, %.o, $(src))
lib=$(notdir $(shell find $(libdir) -name "*.so"))pthread

CXX=g++
CXXFLAGS=-std=c++11 -g -O3 -Wall 
CXXLIB=-I$(incdir) -L$(libdir) -l$(lib)

$(target):$(obj)
	$(CXX) $(CXXFLAGS) $(CXXLIB) -o $@ $^

%.o:$.cpp
	$(CXX) -c $(CXXFLAGS) $< -o $@

echo:
	@echo $(target)
	@echo $(obj)
	@echo $(src)
	@echo $(CXXLIB)

clean:
	rm $(obj) $(target) -f

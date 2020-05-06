bindir=./bin
srcdir=./src
objdir=./obj
libdir=./lib
incdir=./include

target=$($bindir)/main
subdir=$(shell ls -d $(srcdir)/*/)
subsrc=$(shell find $(subdir) -name "*.cpp")
src=$(wildcard $(srcdir)/*.cpp) $(subsrc)
obj=$(patsubst $(srcdir)/%.cpp, $(objdir)/%.o, $(src))
lib=$(notdir $(shell find $(libdir) -name "*.so"))pthread

CXX=g++
CXXFLAGS=-Wall -std=c++11 -g
CXXLIB=-I$(incdir) -L$(libdir) -l$(lib)

$(target):$(obj)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(CXXLIB)

$(obj):$(src)
	$(CXX) $(CXXFLAGS) $<

echo:
	@echo $(target)
	@echo $(obj)
	@echo $(src)
	@echo $(CXXLIB)

clean:
	rm $(obj) $(target) -f



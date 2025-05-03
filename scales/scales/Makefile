appname = scales

CXX = g++
CXXFLAGS = -std=c++11

srcfiles = $(shell find . -name "*.cpp")
objects  = $(patsubst % .cpp, % .o, $(srcfiles))

all: $(appname)

$(appname): $(objects)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $(appname) $(objects) $(LDLIBS)

clean:
	rm -f $(appname)


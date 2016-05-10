PROJECT = tourist

CXX = g++
CXXFLAGS += -Wall -MD #-ggdb
LIBS = -lpanel -lncurses -lm

SRCS := $(wildcard *.cpp)
OBJS := $(SRCS:.cpp=.o)
DEPS := $(OBJS:.o=.d)

all: $(PROJECT)

%.o: %.cpp Makefile
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(PROJECT): $(OBJS) Makefile
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(PROJECT) $(LIBS)

clean:
	rm -f $(OBJS) $(DEPS) $(PROJECT)


deps: $(SRCS)
	$(CXX) -MD -E $(SRCS) > /dev/null

wc:
	wc *.cpp *.hpp *.T Makefile

-include $(DEPS)

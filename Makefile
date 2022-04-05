TARGET := plugin.so

CXX := g++
CXXFLAGS := -m32 -fPIC -Wall -Werror

LD := g++
LDFLAGS := -m32 -shared

SRC := $(wildcard *.cpp)
OBJ := $(patsubst %.cpp,%.o,$(SRC))

all: $(TARGET)

$(TARGET): $(OBJ)
	$(LD) $(LDFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f $(TARGET) $(OBJ)

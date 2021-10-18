CFLAGS := -Wall -std=c++17
CPPFLAGS := -MMD
CXX := g++

TARGET := bin/DataBase

SOURCES := $(wildcard src/DataBase/main.cpp)
LIBSOURCES := $(wildcard src/lib/*.cpp)

LIBOBJ := $(patsubst src/lib/%.cpp, obj/src/%.o, $(LIBSOURCES))
LIB := obj/lib/functionLib.a

OBJ := $(patsubst src/DataBase/%.cpp, obj/src/%.o, $(SOURCES))

all:$(TARGET)

$(TARGET): $(LIB) $(OBJ)
	$(CXX) $(CFLAGS) $(CPPFLAGS) -o $(TARGET) $(OBJ) -L. $(LIB)  

$(LIB): $(LIBOBJ)
	ar rcs $@ $^

obj/src/%.o: src/lib/%.cpp
	$(CXX) $(CPPFLAGS) $(CFLAGS) -c $< -o $@  -I src/lib 

obj/src/%.o: src/DataBase/%.cpp
	$(CXX) $(CPPFLAGS) $(CFLAGS) -c -DHASH_M $< -o $@  -Isrc/lib  

run: $(TARGET)
	./bin/DataBase

rebuild: clean all

clean:
	find . -name "*.o" -exec rm '{}' \;
	find . -name "*.d" -exec rm '{}' \;
	find . -name "*.a" -exec rm '{}' \;
	find . -name "*.out" -exec rm '{}' \;
	find ./bin -type f -name "DataBase" -exec rm -f '{}' \;

format:
	cd src/lib; find . -name "*.cpp" -exec clang-format -i {} \;
	cd src/lib; find . -name "*.h" -exec clang-format -i {} \;

.PHONY: clean run all format rebuild

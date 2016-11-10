C:=gcc
CFLAGS:=-I. -fpic
SRC := src/sockutil.c
OBJ := build/sockutil.o

all: build/libsockutil.so build/sockutil.a

build/libsockutil.so: $(OBJ)
	$(CC) -shared -o $@ $^

build/sockutil.a: $(OBJ)
	ar -rs $@ $^

build/sockutil.o: 
	mkdir -p build/include
	cp src/sockutil.h build/include/sockutil.h
	$(CC) -c -o $@ $(SRC) $(CFLAGS)

clean:
	rm -rf build

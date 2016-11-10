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

test:
	mkdir -p build/test
	mkdir -p bin/test 
	$(CC) -c test/server.c -o build/test/server.o
	$(CC) -c test/client.c -o build/test/client.o
	$(CC) -o bin/test/server build/test/server.o build/sockutil.a
	$(CC) -o bin/test/client build/test/client.o build/sockutil.a

clean:
	rm -rf build
	rm -rf bin

.PHONY: all test clean

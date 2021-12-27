CC=g++
# CFLAGS=--std=c++11
SRC=src/*.cpp
EXEC=bin/axelrod
DIRS=bin

all: $(EXEC)

bin/axelrod: $(SRC)
	$(CC) -o $@ $^

clean:
	rm -rf bin

# will create all necessary directories after the Makefile is parsed
$(shell mkdir -p $(DIRS))

CC=g++
CFLAGS=-I include/
BIN=bin/axelrod
OBJ=obj/aleat.o obj/duel.o obj/PierreFeuilleCiseaux.o obj/DilemnePrisonnier.o obj/main.o
DIRS=obj bin

all: $(BIN)

$(BIN): $(OBJ)
	$(CC) -o $@ $^

obj/main.o: src/main.cpp include/DilemnePrisonnier.h include/PierreFeuilleCiseaux.h include/duel.h include/aleat.h
	$(CC) -o $@ -c $< $(CFLAGS)

obj/PierreFeuilleCiseaux.o: src/PierreFeuilleCiseaux.cpp include/PierreFeuilleCiseaux.h include/duel.h include/aleat.h
	$(CC) -o $@ -c $< $(CFLAGS)

obj/DilemnePrisonnier.o: src/DilemnePrisonnier.cpp include/DilemnePrisonnier.h include/duel.h include/aleat.h
	$(CC) -o $@ -c $< $(CFLAGS)

obj/duel.o: src/duel.cpp include/duel.h
	$(CC) -o $@ -c $< $(CFLAGS)

obj/aleat.o: src/aleat.cpp include/aleat.h
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -rf obj

mrproper:
	rm -rf obj bin

.PHONY: clean mrproper

# will create all necessary directories after the Makefile is parsed
$(shell mkdir -p $(DIRS))

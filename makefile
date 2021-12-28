CC=g++
CFLAGS=-I include/
OBJ=obj/duel.o obj/PierreFeuilleCiseaux.o obj/DilemnePrisonnier.o obj/main.o
DIRS=obj bin

all: bin/axelrod

bin/axelrod: $(OBJ)
	$(CC) -o $@ $^

obj/main.o: src/main.cpp include/DilemnePrisonnier.h include/PierreFeuilleCiseaux.h include/duel.h
	$(CC) -o $@ -c $< $(CFLAGS)

obj/PierreFeuilleCiseaux.o: src/PierreFeuilleCiseaux.cpp include/PierreFeuilleCiseaux.h include/duel.h
	$(CC) -o $@ -c $< $(CFLAGS)

obj/DilemnePrisonnier.o: src/DilemnePrisonnier.cpp include/DilemnePrisonnier.h include/duel.h
	$(CC) -o $@ -c $< $(CFLAGS)

obj/duel.o: src/duel.cpp include/duel.h
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -rf obj

mrproper:
	rm -rf obj bin

# will create all necessary directories after the Makefile is parsed
$(shell mkdir -p $(DIRS))

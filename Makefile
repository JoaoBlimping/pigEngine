#just saying this is a hella good makefile I think
#remember this one for later days <3
#legit a lot of love has gone into this makefile

CC = emcc
FLAGS = -s USE_SDL=2 -s USE_SDL_IMAGE=2

FILENAME:= $(patsubst src/%.cc,bin/%.bc,$(wildcard src/*.cc))


bin/%.bc: src/%.cc
	$(CC) $< $(FLAGS) -o $@

bin/%.bc: src/*/%.cc
	$(CC) $< $(FLAGS) -o $@

all: $(FILENAME)
	echo $(FILENAME)
	$(CC) $(FILENAME) $(FLAGS) -o bin/main.html -O2 --preload-file assets

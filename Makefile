#makefile is finally sexy

CC = emcc
FLAGS = -s USE_SDL=2 -s USE_SDL_IMAGE=2
ASSETS = assets

FILENAME = $(patsubst src/%.cc,bin/%.bc,$(wildcard src/*.cc)) \
	$(patsubst src/%.cc,bin/%.bc,$(wildcard src/*/*.cc))

SOURCES = src/*.cc src/*/*.cc

bin/%.bc: src/%.cc
	mkdir -p $(@D)
	$(CC) $< $(FLAGS) -o $@

all:
	$(CC) $(SOURCES) $(FLAGS) -o release/main.html -O2 --preload-file $(ASSETS)

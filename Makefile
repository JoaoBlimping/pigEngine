#makefile is finally sexy

CC = emcc
FLAGS = -s USE_SDL=2 -s USE_SDL_IMAGE=2 -s SDL2_IMAGE_FORMATS="['png']"
ASSETS = assets

FILENAME = $(patsubst src/%.cc,bin/%.bc,$(wildcard src/*.cc)) \
	$(patsubst src/%.cc,bin/%.bc,$(wildcard src/*/*.cc))

SOURCES = src/*.cc src/*/*.cc

all:
	$(CC) $(SOURCES) $(FLAGS) -o release/main.html -O2 --preload-file $(ASSETS)

#makefile is finally sexy

CC = emcc
FLAGS = -s USE_SDL=2 -s USE_SDL_IMAGE=2 -s SDL2_IMAGE_FORMATS="['png']"
ASSETS = assets

FILENAME = $(patsubst src/%.cc,bin/%.bc,$(wildcard src/*.cc)) \
	$(patsubst src/%.cc,bin/%.bc,$(wildcard src/*/*.cc))

SOURCES = src/*.cc src/*/*.cc

PIG_SCRIPT = /home/daly/projects/tools/pigScript/src
DANYLIB = /home/daly/projects/tools/danylib/src


all:
	#copy the pigScript files into the src/pigScript folder
	cp -r $(PIG_SCRIPT) src/pigScript
	cp -r $(DANYLIB) src/pigScript/danylib

	#the building part
	$(CC) $(SOURCES) $(FLAGS) -o release/main.html -O2 --preload-file $(ASSETS)


clean:
	#remove pigScript again
	rm -r -f src/pigScript

CC = emcc
FLAGS = -s USE_SDL=2 -s USE_SDL_IMAGE=2
SOURCES = src/*.cc src/*/*.cc src/mixer/mixer.c

release:
	$(CC) $(SOURCES) $(FLAGS) -o bin/main.html -O2 --preload-file assets

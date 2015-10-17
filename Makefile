CC = emcc
FLAGS = -s USE_SDL=2 -s USE_SDL_IMAGE=2

mixer: src/mixer/mixer.c
	$(CC) src/mixer/mixer.c $(FLAGS) -o bin/mixer.bc

bytecode: src/*.cc src/*/*.cc
	$(CC) src/*.cc src/*/*.cc $(FLAGS) -o bin/

release: mixer bytecode
	$(CC) bin/*.bc -o bin/main.html -O2 --preload-file assets

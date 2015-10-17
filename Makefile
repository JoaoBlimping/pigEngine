CC = emcc
FLAGS = -s USE_SDL=2 -s USE_SDL_IMAGE=2

bytecode: src/*.cc src/*/*.cc
	$(CC) src/*.cc src/*/*.cc $(FLAGS) -o bin/$@.bc

release: bytecode
	$(CC) bin/*.bc $(FLAGS) -o bin/main.html -O2 --preload-file assets

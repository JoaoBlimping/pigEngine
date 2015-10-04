CC = emcc
FLAGS = -s USE_SDL=2 -s USE_SDL_IMAGE=2

test:
	$(CC) src/*.cc $(FLAGS) -o bin/main.html --preload-file assets

release:
	$(CC) src/*.cc src/*/*.cc $(FLAGS) -o bin/main.html -O2 --preload-file assets

test:
	emcc src/*.cc -s USE_SDL=2 -o bin/main.html --preload-file assets/hey.bmp

release:
	emcc src/*.cc -s USE_SDL=2 -o bin/main.html -O2 --preload-file assets/hey.bmp

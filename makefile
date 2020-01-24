all: main

main: 
	gcc -o bin/mnist-1lnn -Iutil main.c 1lnn.c util/screen.c util/mnist-utils.c util/mnist-stats.c
	x86_64-w64-mingw32-gcc -o bin/mnist-1lnn -Iutil main.c 1lnn.c util/screen.c util/mnist-utils.c util/mnist-stats.c

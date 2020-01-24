all: main

main: 
	gcc -o bin/linux-build -Iutil main.c 1lnn.c util/screen.c util/mnist-utils.c util/mnist-stats.c
	x86_64-w64-mingw32-gcc -o bin/windows-x64-build -Iutil main.c 1lnn.c util/screen.c util/mnist-utils.c util/mnist-stats.c
	i686-w64-mingw32-gcc -o bin/windows-x32-build -Iutil main.c 1lnn.c util/screen.c util/mnist-utils.c util/mnist-stats.c

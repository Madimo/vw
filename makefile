exec    = vw
objects = main.o init.o global.o writer.o
main    = main.c lib/init.h lib/writer.h
init    = lib/init.c lib/init.h lib/global.h
global  = lib/global.c
writer  = lib/writer.c lib/writer.h lib/global.h

all: $(objects)
	gcc $(objects) -o $(exec)

main.o: $(main)
	gcc -c main.c

init.o: $(init)
	gcc -c lib/init.c

global.o: $(global)
	gcc -c lib/global.c

writer.o: $(writer)
	gcc -c lib/writer.c

.PHONY: rebuild clean
rebuild:
	make clean
	make all

clean:
	-rm $(objects)
	-rm $(exec)


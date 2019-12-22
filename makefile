all: isort txtfind
isort: isort.c 
	gcc -Wall -g isort.c -o isort
txtfind: txtfind.c
	gcc -Wall -g txtfind.c -o txtfind

.PHONY: all clean

clean:
	rm -f isort txtfind

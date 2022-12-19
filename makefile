
CFLAGS = -g -Wall -Wextra -W
LDFLAGS = -lm

CFLAGS = -g -Wall
IFLAGS = -Iinclude
OPATH = obj/
CPATH = src/

vpath %.h include
vpath %.c src
vpath %.o obj
vpath main bin

main : main.o player.o grid.o
	gcc $(CFLAGS) -o main $(OPATH)main.o $(OPATH)player.o $(OPATH)grid.o
	mv $@ bin/

main.o : main.c player.h grid.h
player.o: player.c player.h
grid.o: grid.c grid.h

%.o : 
	gcc $(CFLAGS) -c $< $(IFLAGS)
	mv $@ $(OPATH)

clean : 
	rm obj/* bin/*

doc:
	doxygen Doxyfile
	
archive:
	tar -cf KAYA_RHABY_PASCIA_HERSCHE_DIALLO_ABDOUL_AZIZ.tar.gz *.c *.h makefile level1.txt README.md Doxyfile

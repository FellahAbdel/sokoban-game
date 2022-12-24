S_REP = src/
H_REP = include/
O_REP = obj/
B_REP = bin/
D_REP = doc/

LD_LIBRARY_PATH =/../install_dir/lib

EXEC = $(B_REP)main
SRC = $(wildcard $(S_REP)*.c)
OBJ = $(SRC:$(S_REP)%.c=$(O_REP)%.o)

CFLAGS = -g -Wall -Wextra 
LDFLAGS =  -lm -L/../install_dir -l SDL2 -Wl,-rpath=$(LD_LIBRARY_PATH)

IFLAGS = -I include

$(EXEC) : $(OBJ) | $(B_REP)
	gcc $(CFLAGS) -o $@ $^  $(LDFLAGS)

$(O_REP)%.o : $(S_REP)%.c | $(O_REP)
	gcc -c $< -o $@ $(IFLAGS)

$(B_REP) :
	mkdir $@

clean :
	rm -r $(O_REP)* $(B_REP) 2> /dev/null

doc : 
	doxygen Doxyfile

archive:
	tar -cf KAYA_RHABY_PASCIA_HERSCHE_DIALLO_ABDOUL_AZIZ.tar.gz *.c *.h makefile level1.txt README.md Doxyfile

run:
	cd ./bin/ && ./main

config : 
	cd SDL2 && ./configure --prefix=${PWD}/../install_dir && make install -j6
S_REP = src/
H_REP = include/
O_REP = obj/
B_REP = bin/
D_REP = doc/



EXEC = $(B_REP)main
SRC = $(wildcard $(S_REP)*.c)
OBJ = $(SRC:$(S_REP)%.c=$(O_REP)%.o)

CFLAGS = -g -Wall -Wextra 
LDFLAGS = -lm
IFLAGS = -I include

$(EXEC) : $(OBJ) | $(B_REP)
	gcc $(CFLAGS) -o $@ $^ $(LDFLAGS)

$(O_REP)%.o : $(S_REP)%.c | $(O_REP)
	gcc -c $< -o $@ $(IFLAGS)

$(B_REP) $(O_REP) :

	mkdir $@

clean :
	rm -r $(O_REP) $(B_REP) $(D_REP)

doc : 
	doxygen Doxyfile

archive:
	tar -cf KAYA_RHABY_PASCIA_HERSCHE_DIALLO_ABDOUL_AZIZ.tar.gz *.c *.h makefile level1.txt README.md Doxyfile

run:
	cd ./bin/ && ./main
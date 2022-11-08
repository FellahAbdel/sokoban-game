

CC = gcc

CFLAGS = -Wall -W
LDFLAGS = -lm

SOURCES = $(wildcard *.c)  # SOURCES = main.c liste.c
OBJETS = $(SOURCES:.c=.o)  # Recupère tous les fichiers dans sources, sauf
						   # qu'il faut remplacer les .c par .o
EXEC = prog

all : $(EXEC)

# On genère les fichiers objets à partir des fichiers c
# $@ : Nom de la cible qui provoque l'execution de la commande
# $< : nom de la première dependance
%.o : %.c 
	$(CC) -o $@ -c $<

	
# On genère l'executable à partir de nos fichiers objets
# $^ : Nom de toutes les dependance
$(EXEC) : $(OBJETS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

	rm -rf *.o

doc:
	doxygen Doxyfile

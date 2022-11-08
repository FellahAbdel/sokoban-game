#include <stdio.h>


int main(){
    char *nom = "diallo";
    char *buffer = nom;
    printf("%c\n", *buffer);
    nom = nom + 1;
    printf("%c\n", *nom);


        return 0;
}
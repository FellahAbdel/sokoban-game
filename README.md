# Sokoban

Vous trouverez ici les fichiers de base pour le TP noté concernant le jeu du Sokoban
Les consignes et l'énoncé se trouve à cette address [TP Sokoban](https://techdevprintemps2022.pages.unistra.fr/TP_TechDevEnonce/)

# 1 ère Difficulté :

    Comment faire une allocation dynamique d'un tableau à 2
    dimensions de type enum CaseType ?

    Ressources pour sortir de l'ignorance :
        StackOverflow, Youtube, et Elias

# 2 ème Difficulté :

    Problème de dependance circulaire de player.h et grid.h

    1 ère solution :
        Ecrire le prototype de la fonction movePlayer dans
        grid.h et son développement dans grid.c (Pas trop fin)
    2 ème solution (J'èspere qu'il y en une):
        struct Grid dans player.h
        https://stackoverflow.com/questions/10122621/c-circular-dependency

# 3 ème difficulté :

    Comment stabiliser la cible ?, c'est-à-dire qu'une fois que
    le joueur quitte la cible, elle y reste toujours.

    Solution :
        Dans la deuxième partie.

# KAYA RHABY PASCIA HERSHE & DIALLO ABDOUL AZIZ

#ifndef FONCTION_GRILLE_C
#define FONCTION_GRILLE_C


#include "prototype.h"
#include "fonction_deplacement.c"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>


// Fonction qui permet d'initialiser la grille avec des espaces vides
 void initialise_grille_vide(void){
    unsigned ligne;
    unsigned colonne;
// Double boucle pour parcourir toutes les cases de la grille
    for (colonne = 0; colonne < COLONNES_GRILLE; ++colonne){
        for (ligne = 0; ligne < LIGNES_GRILLE; ++ligne){
            grille[colonne][ligne] = ' ';
            }
    }
}


// Fonction qui permet d'afficher la grille de jeu
 void afficher_grille_jeu(void){
    int colonne;
    int ligne;

    putchar('\n');
    printf("|");
    // Affichage des numéros de colonne
    for (colonne = 1; colonne <= COLONNES_GRILLE; ++colonne){
        printf("  %d ", colonne);
    }
    putchar('\n');
    putchar('*');

    // Affichage de la ligne de séparation
    for (colonne = 1; colonne <= COLONNES_GRILLE; ++colonne){
        printf("---*");
    }
    putchar('\n');

    // Double boucle pour parcourir toutes les cases de la grille
    for (ligne = 0; ligne < LIGNES_GRILLE; ++ligne)
    {
        putchar('|');

        for (colonne = 0; colonne < COLONNES_GRILLE; ++colonne){
            // Si la case contient une lettre, on l'affiche
            if (isalpha(grille[colonne][ligne])){
                printf(" %c |", grille[colonne][ligne]);
            }
            // Sinon, on affiche un espace vide
            else{
                printf(" %c |", ' ');
            }
        }
        putchar('\n');
        putchar('*');

         // Affichage de la ligne de séparation
        for (colonne = 1; colonne <= COLONNES_GRILLE; ++colonne){
            printf("---*");
        }
        putchar('\n');
    }

    // Affichage des numéros de colonne
    for (colonne = 1; colonne <= COLONNES_GRILLE; ++colonne){
        printf("  %d ", colonne);
    }
    putchar('\n');
}

// Fonction qui permet de vérifier si la grille est complète (toutes les cases sont remplies)
 int grille_complete(void){
    unsigned colonne;
    unsigned ligne;

    // Double boucle pour parcourir toutes les cases de la grille
    for (colonne = 0; colonne < COLONNES_GRILLE; ++colonne){
        for (ligne = 0; ligne < LIGNES_GRILLE; ++ligne){
            // Si une case est vide, la grille n'est pas complète
            if (grille[colonne][ligne] == ' '){
                return 0;
            }
        }
    }
    // Sinon, la grille est complète
    return 1;
}


#endif

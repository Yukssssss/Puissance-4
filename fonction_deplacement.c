#ifndef FONCTION_DEPLACEMENT_C
#define FONCTION_DEPLACEMENT_C

#include "prototype.h"
#include "fonction_grille.c"
#include "fonction_joueur.c"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

// Fonction qui calcule la position du coup joué par le joueur
 void calcule_position_coup(int coup_joueur, struct position_cases_grille *position)
{
    int ligne;

    position->colonne = coup_joueur;

    // On parcourt la colonne à partir du bas pour trouver la première case vide
    for (ligne = LIGNES_GRILLE - 1; ligne >= 0; --ligne){
        if (grille[position->colonne][ligne] == ' ')
        {
            position->ligne = ligne;
            break;
        }
    }
}

// Fonction qui calcule le nombre de jetons alignés horizontalement ou verticalement
 unsigned calcule_nb_jetons_hrz_vrt(struct position_cases_grille *position, int deplacement_hrz, int deplacement_vrt, char jeton)
{
    struct position_cases_grille copie_temporaire;
    unsigned nombre = 1; //On initialise le nombre de jetons à 1 car on prend en compte la case de départ


    copie_temporaire.ligne = position->ligne + deplacement_vrt;
    copie_temporaire.colonne = position->colonne + deplacement_hrz;

    // On compte le nombre de jetons alignés dans une direction donnée
    while (position_accepter(&copie_temporaire))
    {
        if (grille[copie_temporaire.colonne][copie_temporaire.ligne] == jeton){  // Si le jeton à la position courante correspond au jeton recherché
            ++nombre;
        }
        else{
            break;
        }


        copie_temporaire.ligne += deplacement_vrt;  // On déplace la ligne de la structure temporaire
        copie_temporaire.colonne += deplacement_hrz;  // On déplace la colonne de la structure temporaire
    }

    return nombre;
}

// Fonction qui retourne la valeur maximale entre deux nombres
 unsigned valeur_max(unsigned nb_1, unsigned nb_2)
{
    if (nb_1 > nb_2) {
        return nb_1;
    }
    else {
        return nb_2;
    }
}

// Fonction qui calcule le nombre de jetons alignés dans toutes les directions
 unsigned calcule_nb_jetons_total(struct position_cases_grille *position, char jeton)
{
    unsigned max;
    //Calcule les jetons verticalement
    max = calcule_nb_jetons_hrz_vrt(position, 0, 1, jeton);

    //Calcule les jetons horizontalement
    max = valeur_max(max, calcule_nb_jetons_hrz_vrt(position, 1, 0, jeton) + calcule_nb_jetons_hrz_vrt(position, -1, 0, jeton) - 1);

    //Calcule les jetons diagonales (en haut a gauche / en bas a droite)
    max = valeur_max(max, calcule_nb_jetons_hrz_vrt(position, 1, 1, jeton) + calcule_nb_jetons_hrz_vrt(position, -1, -1, jeton) - 1);

    //Calcule les jetons diagonales (en bas a gauche / en haut a droite)
    max = valeur_max(max, calcule_nb_jetons_hrz_vrt(position, 1, -1, jeton) + calcule_nb_jetons_hrz_vrt(position, -1, 1, jeton) - 1);

    return max;
}

#endif

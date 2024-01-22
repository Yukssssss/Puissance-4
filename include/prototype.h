#ifndef PROTOTYPE_H
#define PROTOTYPE_H

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

// D�finir des macros pour les jetons, les actions, les dimensions de la grille et le statut du jeu.
#define JETON_JOUEUR_1 ('O')
#define JETON_JOUEUR_2 ('X')


#define ACTION_INVALIDE (0)
#define ACTION_JOUER (1)
#define ACTION_NOUVELLE_POSITION (2)
#define ACTION_QUITTER_JEU (3)

#define COLONNES_GRILLE (7)
#define LIGNES_GRILLE (6)

#define STATUT_OK (0)
#define JOUEUR_GAGNE (1)
#define JOUEUR_EGALITE (2)

// D�finir une structure pour stocker une position dans la grille.
struct position_cases_grille
{
    int ligne;
    int colonne;

};


// D�clarer des fonctions statiques pour initialiser la grille, afficher la grille de jeu, v�rifier si la grille est pleine,
 static void initialise_grille_vide(void);
 static void afficher_grille_jeu(void);
 static int grille_complete(void);

// calculer la position d'un coup, calculer le nombre de jetons dans une ligne, une colonne ou une diagonale, v�rifier si un coup est valide,
 static void calcule_position_coup(int, struct position_cases_grille *);
 static unsigned calcule_nb_jetons_hrz_vrt(struct position_cases_grille *, int, int, char);
 static unsigned calcule_nb_jetons_total(struct position_cases_grille *, char);
 static unsigned valeur_max(unsigned, unsigned);

// demander une action � l'utilisateur, accepter une position dans la grille et d�terminer le statut du jeu.
 static int verifie_coup_valide(int);
 static int demande_action_joueur(int *);
 static int position_accepter(struct position_cases_grille *);
 static int statut_jeu(struct position_cases_grille *pos, char);

// D�clarer des fonctions non statiques pour jouer au jeu et expliquer les r�gles.
void jouer(void);
void comment_jouer(void);

static int choix_quitter(int choix);

// D�clarer une variable statique pour stocker les jetons jou�s par les joueurs.
 char grille[COLONNES_GRILLE][LIGNES_GRILLE];


#endif

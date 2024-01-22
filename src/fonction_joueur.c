#ifndef FONCTION_JOUEUR_C
#define FONCTION_JOUEUR_C


#include "prototype.h"
#include "fonction_deplacement.c"



// Vérifie si un coup est valide, renvoie 1 si c'est le cas, 0 sinon
int verifie_coup_valide(int colonne)
{
    if (colonne <= 0 || colonne > COLONNES_GRILLE || grille[colonne - 1][0] != ' '){
        return 0;
    }
    else{
        return 1;
    }
}

// Demande à l'utilisateur une action à effectuer et la renvoie sous forme d'un entier
int demande_action_joueur(int *coup_joueur)
{

    char lettre;
    int resultat = ACTION_INVALIDE;

     // On récupère l'entrée utilisateur en tentant d'abord de la lire comme un entier
    if (scanf("%d", coup_joueur) != 1)
    {
        // Si la lecture échoue, on essaie de lire une lettre
        if (scanf("%c", &lettre) != 1)
        {
            fprintf(stderr, "Erreur lors de la saisie\n");
            return resultat;
        }

        switch (lettre)
        {
        case 'M':
        case 'm':
            resultat = ACTION_QUITTER_JEU;
            system("cls");
            main();
        default:
            resultat = ACTION_NOUVELLE_POSITION;
            break;
        }
    }
    else{
        resultat = ACTION_JOUER;
    }
    return resultat;
}



// Vérifie si une position est valide dans la grille, renvoie 1 si c'est le cas, 0 sinon
int position_accepter(struct position_cases_grille *position)
{

    int resultat = 1;

    if (position->colonne >= COLONNES_GRILLE || position->colonne < 0){
        resultat = 0;
    }
    else if (position->ligne >= LIGNES_GRILLE || position->ligne < 0){
        resultat = 0;
    }

    return resultat;
}


// Renvoie le statut du jeu pour une position donnée et un jeton donné
int statut_jeu(struct position_cases_grille *position, char jeton)
{

    // Si la grille est complète, c'est une égalité
    if (grille_complete()){
        return JOUEUR_EGALITE;
    }
    // Si le nombre de jetons alignés est supérieur ou égal à 4, le joueur a gagné
    else if (calcule_nb_jetons_total(position, jeton) >= 4){
        return JOUEUR_GAGNE;
    }
    // Sinon, le statut est OK
    return STATUT_OK;
}



#endif

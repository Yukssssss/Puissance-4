#ifndef INTERFACE_C
#define INTERFACE_C

#include "prototype.h"
#include "fonction_grille.c"

int choix_quitter(int choix)
{
    while(1){
        scanf("%d", &choix);
        switch (choix)
        {
            case 0:
                system("cls");
                printf("Etes vous sur de vouloir quitter ? (1 pour oui, 0 pour revenir au menu)\n");
                while(1){
                    int confirmation=1;
                    scanf("%d", &confirmation);
                    if(confirmation==1){
                        printf("Au revoir !");
                        exit(0); // quitter le programme avec succès
                    }
                    else if(confirmation==0){
                        system("cls");
                        return 0; // retourner à la boucle principale avec le choix initial
                    }
                    else{
                        printf("Choix invalide. Ressayer.\n");
                    }
                }
            case 1:
                // Effacement de l'écran puis lancement de la fonction comment_jouer
                system("cls");
                return choix; // retourner à la boucle principale avec le choix initial
                break;

            default:
                // Affichage d'un message d'erreur pour un choix invalide
                printf("Choix invalide. Veuillez choisir entre 1 et 0\n");
                break;
        }
    }
}

// Fonction principale qui permet de jouer au jeu
void jouer(void){
    int jouer = 1;
    char jeton = JETON_JOUEUR_1;
    int statut;

    initialise_grille_vide();
    afficher_grille_jeu();

    // Boucle principale du jeu
    while (jouer)
    {
        int coup_joueur;
        struct position_cases_grille position;
        int action;


         // Affiche les options pour le joueur
        printf("\n\n[MENU PRINCIPAL] : M ou m");
        printf("\n[JOUER] : 1 a 7 \n\n");

        // Affiche le tour du joueur en cours
        if(jeton == JETON_JOUEUR_1) {
                printf("Jeton joueur 1 : %c\n", JETON_JOUEUR_1);
            printf("Joueur 1 : ");
        }
        else {
            printf("Joueur 2 : ");
            printf("Jeton joueur 2 : %c\n", JETON_JOUEUR_2);
        }

        // Demande au joueur de faire une action (jouer, quitter)
        action = demande_action_joueur(&coup_joueur);

        // Vérifie si l'action du joueur est invalide
        if (action == ACTION_INVALIDE){
            return EXIT_FAILURE;
        }
         // Si le joueur choisit de quitter le jeu
        else if (action == ACTION_QUITTER_JEU){
            return 0;
        }
        // Si le coup choisi par le joueur n'est pas valide
        else if (action == ACTION_NOUVELLE_POSITION || !verifie_coup_valide(coup_joueur))
        {
            fprintf(stderr, "Vous ne pouvez pas jouer a cet endroit\n");
            continue;
        }

        // Calcule la position du coup choisi par le joueur
        calcule_position_coup(coup_joueur - 1, &position);
        grille[position.colonne][position.ligne] = jeton;
        afficher_grille_jeu();
        statut = statut_jeu(&position, jeton);

        // Si aucun joueur n'a gagné ou pas d'égalité le jeu continue
        if (statut != STATUT_OK){
            break;
        }
        // Change de joueur
        if (jeton == JETON_JOUEUR_1) {
            jeton = JETON_JOUEUR_2;
        } else {
            jeton = JETON_JOUEUR_1;
        }
    }

    // Si le joueur a gagné la partie
    if (statut == JOUEUR_GAGNE){
         // Affiche le gagnant de la partie
        if (jeton == JETON_JOUEUR_1) {
            printf("! Bravo ! Le joueur 1 a gagne\n");
        } else {
            printf("! Bravo ! Le joueur 2 a gagne\n");
        }
        printf("Voulez-vous retourner au menu principal ? (1 pour oui, 0 pour quitter)\n");
        choix_quitter(jouer);
    }


    else if(statut == JOUEUR_EGALITE){
        printf("! Dommage ! Egalite\n");
        printf("Voulez-vous retourner au menu principal ? (1 pour oui, 0 pour quitter)\n");
        choix_quitter(jouer);
    }
    return 0;
}


//Cette fonction affiche la notice du jeu de puissance 4
void comment_jouer(void){

    int menu = 1;
    printf("*******************************************\n");
    printf("**                                       **\n");
    printf("**         NOTICE JEU CONNECT 4          **\n");
    printf("**                                       **\n");
    printf("*******************************************\n\n\n");

    printf("Le jeu de Puissance 4 est un jeu de strategie pour deux joueurs. Les joueurs doivent placer leurs jetons (disques) de leur couleur respective sur une grille verticale de 7 colonnes et 6 lignes.\n");
    printf("Le but est d'aligner 4 jetons de sa couleur soit horizontalement, verticalement ou en diagonale. Le premier joueur a reussir cet alignement remporte la partie.\n\n");
    printf("Les jetons du joueur 1 sont representes par le caractere 'O' et ceux du joueur 2 par le caractere 'X'.\nLes colonnes sont numerotees de 1 a 7 et les lignes de 1 a 6.\n\n");
    printf("Le joueur 1 commence en premier. A chaque tour, le joueur choisit la colonne ou il souhaite placer son jeton en entrant le numero correspondant\n");
    printf("Si la colonne est pleine, le joueur doit en choisir une autre. Le jeu continue jusqu'a ce qu'un joueur aligne 4 jetons de sa couleur ou que la grille soit completement remplie sans vainqueur, ce qui entraine une egalite.\n\n");

    printf("Bonne partie !\n\n");
    printf("Voulez-vous retourner au menu principal ? (1 pour oui, 0 pour quitter) ");
    choix_quitter(menu);



}




#endif

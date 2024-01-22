#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include "fonction_grille.c"
#include "fonction_deplacement.c"




int main(void)
{

    int choix;
    while (1) {
        // Affichage du menu principal
        printf("*******************************************\n");
        printf("**                                       **\n");
        printf("**         MENU PRINCIPAL CONNECT 4      **\n");
        printf("**                                       **\n");
        printf("*******************************************\n\n");

        // Affichage des options du menu principal
        printf("-------------------------------------------\n");
        printf("|         QUE VOULEZ-VOUS FAIRE ?         |\n");
        printf("-------------------------------------------\n\n\n");
        printf("1) [CONNECT 4] Jouer au jeu\n");
        printf("2) [NOTICE] Comment Jouer ?\n");
        printf("3) [QUITTER CONSOLE]\n\n");
        printf("Votre choix : ");

        scanf("%d", &choix);

        switch (choix)
        {
            case 1:
                // Effacement de l'écran puis lancement de la fonction jouer
                system("cls");
                jouer();
                break;
             case 2:
                 // Effacement de l'écran puis lancement de la fonction comment_jouer
                system("cls");
                comment_jouer();
                break;
            case 3:
                // Effacement de l'écran puis affichage d'un message de sortie
                system("cls");
                while (1) {
                    int etre_sur;
                    printf("Etes-vous sur ? (1 pour oui, 0 pour revenir au menu)\n");
                    scanf("%d", &etre_sur);

                    if (etre_sur == 1) {
                        printf("Au revoir !");
                        exit(0);
                    }
                    else if (etre_sur == 0) {
                        system("cls");
                        main();
                    }
                    else {
                        printf("Veuillez entrer une reponse valide.\n");
                    }
                }
            default:
                system("cls");
                printf("VEUILLEZ ENTRER UN CHOIX VALIDE\n");
        }
    }
}




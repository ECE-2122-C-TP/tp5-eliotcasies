#include <stdio.h>
#include "exercices.h"




int main() {
    int choix = 0; // Initialisation du choix de l'utilisateur
    do
    {
        printf("\nVeuillez choisir le numéro de votre exercice (1, 2, ou 3) ou 0 pour arrêter le programme : ");
        scanf("%d", &choix);
        while (0 > choix || choix > 3) {
            printf("Erreur, vous n'avez pas choisi un chiffre compris entre 0 et 3\n"
                   "Veuillez à nouveau choisir un chiffre :");
            scanf("%d", &choix);
        }
        switch (choix) {
            case 1 : {
                exercice1();
                break;
            }
            case 2 : {
                exercice2();
                break;
            }
            case 3 : {
                exercice3();
                break;
            }
        }
    }
    while ( choix != 0);
    printf("Fin du programme.");

    return 0;
}

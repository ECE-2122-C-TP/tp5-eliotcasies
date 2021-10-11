//
// Created by CASIES Eliot  on 06/10/2021.
//

#include "exercices.h""
#include "fonctions.h"
#define TAILLE_TABLEAU_MAX 100
#define NB_COLONNES 4
#define NB_LIGNES 3




void exercice1()
{
    int choix = 0; // Initialisation du choix de l'utilisateur
    printf("Veuillez choisir un nombre entre 1 et 6 \n"
           "1 : Fonction de saisie d'un nombre rationnel\n"
           "2 : Fonction d'affichage d'un nombre rationnel\n"
           "3 : Fonction de multiplication de 2 nombre rationnel\n"
           "4 : Fonction d'addition de 2 nombre rationnel\n"
           "5 : Fonction qui trouve le PGDC d'un numérateur et d'un denominateur\n"
           "6 : Fonction de simplification d'un nombre rationnel\n");
    scanf("%d", &choix);
    while (1>choix || choix>6) // Si l'utilisateur ne rentre pas le bon chiffre on le fait recommencer
    {
        printf("Erreur, vous n'avez pas choisi un chiffre compris entre 1 et 6\n"
               "Veuillez à nouveau choisir un chiffre :");
        scanf("%d", &choix);
    }
    switch (choix)
    {
        case 1 : // 1ère fonction
        {
         saisirnombrerationnel();
         break;
        }
        case 2 : // 2ème fonction
        {
            NombreRationnel nombre = saisirnombrerationnel(); // On lui demande d'abord un nombre rationnel pour le rentrer dans la fonction afficher
            printf("Votre nombre rationnel est %d/%d et vaut ", nombre.numerateur, nombre.denominateur  );
            affichernombrerationnel(nombre); // On utilise la fonction créé dans le fonctions.c
            break;
        }
        case 3 : // 3ème fonction
        {
            NombreRationnel nombre1 = saisirnombrerationnel(); // On lui demande d'abord un nombre rationnel pour le rentrer dans la fonction multiplication
            printf("Votre premier nombre rationnel est %d/%d et vaut   ",nombre1.numerateur, nombre1.denominateur);
            affichernombrerationnel(nombre1); // On lui montre le nombre rationnel créé
            NombreRationnel nombre2 = saisirnombrerationnel(); // On lui demande d'abord un nombre rationnel pour le rentrer dans la fonction multiplication
            printf("Votre deuxième nombre rationnel est %d/%d et vaut ",nombre2.numerateur, nombre2.denominateur);
            affichernombrerationnel(nombre2); // On lui montre le nombre rationnel créé
            NombreRationnel nouveaunombre = multiplication(nombre1, nombre2); // On utilise la fonction créé dans le fonctions.c
            printf("La multiplication de ces deux nombres rationnels est %d/%d et vaut ",nouveaunombre.numerateur, nouveaunombre.denominateur);
            affichernombrerationnel(nouveaunombre); // On lui montre le resultat
            break;
        }
        case 4 : // 4ème fonction
        {
            NombreRationnel nombre1 = saisirnombrerationnel(); // On lui demande d'abord un nombre rationnel pour le rentrer dans la fonction addition
            printf("Votre premier nombre rationnel est %d/%d et vaut ",nombre1.numerateur, nombre1.denominateur);
            affichernombrerationnel(nombre1); // On lui montre le nombre rationnel créé
            NombreRationnel nombre2 = saisirnombrerationnel(); // On lui demande d'abord un nombre rationnel pour le rentrer dans la fonction addition
            printf("Votre deuxième nombre rationnel est %d/%d et vaut ",nombre2.numerateur, nombre2.denominateur);
            affichernombrerationnel(nombre2); // On lui montre le nombre rationnel créé
            NombreRationnel nouveaunombre = addition(nombre1, nombre2); // On utilise la fonction créé dans le fonctions.c
            printf("L'addition de ces deux nombres rationnels est %d/%d et vaut ",nouveaunombre.numerateur, nouveaunombre.denominateur);
            affichernombrerationnel(nouveaunombre); // On lui montre le resultat
            break;
        }
        case 5 : // 5ème fonction
        {
            NombreRationnel nombre = saisirnombrerationnel(); // On lui demande d'abord un nombre rationnel pour le rentrer dans la fonction pgdc
            int p=0;
            p = pgdc(nombre); // On utilise la fonction créé dans le fonctions.c
            printf("Le plus grand diviseur commun entre ce numerateur et ce denominateur est %d", p); // On lui montre le resultat
            break;
        }
        case 6 : // 6ème fonction
        {
            NombreRationnel nombre = saisirnombrerationnel();
            int pgcd = pgdc(nombre); // On prend le plus grand diviseur commun trouvé grâce à la fonction pgdc
            if (pgcd==0)
            {
                printf("Le nombre rationnel n'est pas simplifiable."); // Pas simplifiable si pas de plus grand diviseur commun
            }
            else
            {
                int nouveaunumerateur = 0, nouveaudenominateur = 0;
                nouveaudenominateur = nombre.denominateur/pgcd ; // On simplifie le denominateur par le plus grand diviseur commun
                nouveaunumerateur = nombre.numerateur/pgcd; // On simplifie le denominateur par le plus grand diviseur commun
                NombreRationnel nouveaunombre = {nouveaunumerateur, nouveaudenominateur};
                printf("Votre nombre rationnel %d/%d est simplifiable en %d/%d et vaut ", nombre.numerateur, nombre.denominateur, nouveaunombre.numerateur, nouveaunombre.denominateur  );
                affichernombrerationnel(nouveaunombre);
                break;
            }
        }
    }
    printf("\nFin de l'exercice 1.\n");
}

void exercice2()
{
    int tableauEntiers[TAILLE_TABLEAU_MAX] = {0};
    int taillelogique = remplirTableau(tableauEntiers);
    printf("L'élément le plus grand du tableau est %d\n", elementmaxduntableau(tableauEntiers, taillelogique)); // Utilisation de la fonction qui donne le max
    printf("Fin de l'exercice 2.\n");

}

void exercice3()
{
    int tableau2D[NB_LIGNES][NB_COLONNES] = {{0}}; // Initialisation du tableau 3x4
    remplirTableau2D(tableau2D); // Remplissage
    int tableau1D[NB_LIGNES*NB_COLONNES] = {0}; // Initialisation du tableau 1D
    int i = 0, j = 0;
    for (i=0; i<NB_LIGNES; i++)
    {
        for (j=0; j<NB_COLONNES; j++)
        {
            tableau1D[i*NB_COLONNES + j] = tableau2D[i][j]; // La case de coordonées i,j sera la (i*nbcolonnes + j )ème cases du tableau 1D car il y a nbcolonnes par ligne
        }
    }
    int k = 0;
    printf("Votre nouveau tableau est :\n ");
    for (k=0; k<NB_COLONNES*NB_LIGNES; k++)
    {
        printf("%d ", tableau1D[k]);
    }
    printf("\nFin de l'exercice 3.\n");
}

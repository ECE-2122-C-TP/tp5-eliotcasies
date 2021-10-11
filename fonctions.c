//
// Created by CASIES Eliot  on 06/10/2021.
//

#include <stdio.h>
#include "fonctions.h"
#define TAILLE_TABLEAU_MAX 100
#define NB_COLONNES 4
#define NB_LIGNES 3



NombreRationnel saisirnombrerationnel()
{
    NombreRationnel n; /* On définit notre nombre "n" qui est de type NombreRationnel */
    printf("Veuillez saisir le numérateur et le dénominateur du nombre rationnel :");
    scanf("%d %d", &n.numerateur, &n.denominateur); /* On assimile son numérateur et son dénominateur à "n" */
    return n;
}


void affichernombrerationnel(NombreRationnel n){
    float nombre=0; /* Initialisation du nombre rationnel sous forme décimale */
    nombre = (float) n.numerateur / (float) n.denominateur; /* Calcul du nombre */
    printf("%f \n", nombre);
}


NombreRationnel multiplication(NombreRationnel nombre1, NombreRationnel nombre2){
    int nouveaunumerateur=0, nouveaudenominateur=0; /* Initialisation des nouveaux numérateurs, dénominateurs */
    nouveaunumerateur = nombre1.numerateur * nombre2.numerateur; /* Calcul du nouveau numérateur */
    nouveaudenominateur = nombre1.denominateur * nombre2.denominateur; /* Calcul du nouveau dénominateur */
    NombreRationnel nouveaunombre = {nouveaunumerateur, nouveaudenominateur};
    return nouveaunombre;
}


NombreRationnel addition(NombreRationnel nombre1, NombreRationnel nombre2){
    int nouveaudenominateur=0, nouveaunumerateur=0; // Initialise les nouveau dénominateur, numérateur
    nouveaudenominateur = nombre1.denominateur * nombre2.denominateur; // Calcul
    nouveaunumerateur = nombre1.numerateur * nombre2.denominateur + nombre2.numerateur * nombre1.denominateur ; // Calcul
    NombreRationnel nouveaunombre = {nouveaunumerateur, nouveaudenominateur}; // Affectation
    return nouveaunombre;
}


int plusgranddiviseur(int nombre1, int nombre2)
{
    int diviseur = 0; // Initialise le plus grand diviseur que l'on va rechercher
    if (nombre2>=nombre1)
    {
        diviseur = nombre1; // Le plus grand diviseur de nombre1 inferieur à nombre2 est donc nombre1 ici
    }
    else
    {
        diviseur=nombre2; // Sinon on commence les recherches à partir de nombre2
    }
    while ((nombre1%diviseur!=0) && diviseur!=1) // Tant que le nombre1 n'est pas divisible par la variable on diminue sa valeur jusqu'a trouver un diviseur
    {
        diviseur--;
    }
    if (diviseur==1) // Ici la variable est descendu à 1 donc il n'y a pas de diviseur
    {
        return 0;
    }
    else // Sinon on retourne le diviseur trouvé
    {
        return diviseur;
    }

}


int pgdc(NombreRationnel nombre)
{
    int p = nombre.numerateur;// On initialise le pgdc que l'on va chercher, on commence donc avec p le plus grand donc p=numérateur
    while ((p!=0) && (nombre.denominateur%p!=0)) // Tant que le denominateur n'est pas divisible par le diviseur du numerateur (ici p) on continue de chercher
    {
        p = plusgranddiviseur(nombre.numerateur, p-1); // On affecte donc à p le prochain diviseur du numérateur plus petit que le précédent
    }
    if (p==0) // Si pas de diviseur trouvé
    {
        return 0;
    }
    else // Si diviseur trouvé
    {
        return p;
    }

}

    int remplirTableau(int tableauEntiers[])
    {
    int tailleVoulue = 0;
    printf("Combien d'entiers voulez-vous mettre dans votre tableau ?\n");
    scanf("%d", &tailleVoulue);
    while (tailleVoulue > TAILLE_TABLEAU_MAX)
    {
        printf("Erreur, la taille du tableau est limitée à %d éléments, veuillez rentrer à nouveau une taille :", TAILLE_TABLEAU_MAX);
        scanf("%d", &tailleVoulue);
    }
    printf("Veuillez entrer les valeurs du tableau :\n");
    for (int i = 0; i < tailleVoulue; i++)
    {
        scanf("%d", &tableauEntiers[i]);
    }
    return tailleVoulue;  // Renvoi la taille logique du tableau
}


int elementmaxduntableau(int tableauEntiers[], int taillelogique)
{
    int i = 1, maximum=tableauEntiers[0]; // Initialise le maximum au premier element du tableau
    for (i=1; i < taillelogique; i++)
    {
        if (tableauEntiers[i]>maximum) // Si element plus grand que le maximum
        {
            maximum=tableauEntiers[i]; // On remplace le maximum
        }
    }
    return maximum;
}

void remplirTableau2D(int tableauEntiers[NB_LIGNES][NB_COLONNES])
{
    int i = 0, j = 0;
    for (i=0; i<NB_LIGNES; i++)
    {
        printf("Veuillez saisir les entiers de la ligne %d :",i+1);
        for (j=0; j<NB_COLONNES; j++)
        {
            scanf("%d", &tableauEntiers[i][j]);
        }
    }

}

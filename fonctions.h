//
// Created by CASIES Eliot  on 06/10/2021.
//

#include <stdio.h>

#ifndef TD5_ELIOTCASIES_FONCTIONS_H
#define TD5_ELIOTCASIES_FONCTIONS_H
#define NB_COLONNES 4
#define NB_LIGNES 3





typedef struct {
    int numerateur, denominateur;
} NombreRationnel;


NombreRationnel saisirnombrerationnel();
void affichernombrerationnel(NombreRationnel n);
NombreRationnel multiplication(NombreRationnel nombre1, NombreRationnel nombre2);
NombreRationnel addition(NombreRationnel nombre1, NombreRationnel nombre2);
int plusgranddiviseur(int nombre1, int nombre2); // Cherche le plus grand diviseur de nombre1 qui est inférieur ou égal à nombre2
int pgdc(NombreRationnel n); // Donne le pgdc du numerateur et denominateur d'un nombre rationnel
int remplirTableau(int tableauEntiers[]); // Fonction qui crée un tableau et renvoie sa taille logique
int elementmaxduntableau(int tableauEntiers[], int taillelogique); // Donne l'element max d'un tableau
void remplirTableau2D(int tableauEntiers[NB_LIGNES][NB_COLONNES]);


#endif //TD5_ELIOTCASIES_FONCTIONS_H



#ifndef STRUCTURE_H_INCLUDED
#define STRUCTURE_H_INCLUDED
#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>

typedef struct Contraintes Contraintes;
typedef struct Variable Variable;
typedef struct Pb Pb;

struct Contraintes
{
    int indice;//le numero de la contrainte
    int nbContr;//nb d entites dans chaque contraintes
    int* ListeContr;//Selon la contrainte donne la liste des variables dependante de cette derniere
};

struct Variable
{
    int indice;//Le nom de la variable
    int nbValeurs;// Nb de valeurs prises par la variable
    int* Val; //Tableau contenant les valeurs de la variable
    std::vector < std::vector<int> > ListContrVar;// Contient les contraintes de la variable et les variables avec lequelles elle depend
};

struct Pb
{
    int nbVar;//Nombre de variables
    int NbTotContr;//Nombre de regles ou contraintes differentes
    Contraintes* Cpb;//Tableau contenant la definition de chaque contrainte
    Variable* var;//Tableau contenant l'ensemble des variables et ses ensembles de definition
};

Pb* lecture(char* MonF);
void affichage(Pb* MonPb);
#endif // STRUCTURE_H_INCLUDED

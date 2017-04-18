#include <iostream>
#include "Structure.h"
#include <fstream>

using namespace std;
int DefnbCont(char* MonF)
{
    ifstream in(MonF);
     string ligne; //Création d'une chaine de caractere
    int nbLignes = 0;
    while(std::getline(in, ligne)) //On lit chaque ligne du fichier que l'on stoke dans "ligne"
    nbLignes++;
    //cout<<nbLignes; //Affichage Test nombres de ligne
    in.close(); //On ferme le fichier
    return nbLignes;
}

Pb* lecture(char* MonF)
{
    int nbLignes =0;
    nbLignes=DefnbCont(MonF);
    ifstream lectureEnCours(MonF);//debut de lecture
    Pb* lePb =new Pb;
    //bool test =true;
    //pb
    lePb->nbVar=0;
    lectureEnCours>>lePb->nbVar;//Lecture nb de variable
    lePb->NbTotContr =0;
    lePb->Cpb = NULL;
    lePb->var = NULL;//boucle for
    lePb->var= new Variable[lePb->nbVar];//Creation du tableau contenant des cases de type variables
    //var
    for(int i= 0; i<lePb->nbVar; i++)
    {
        lePb->var[i].indice=0;
        lePb->var[i].nbValeurs=0;
        lePb->var[i].Val=NULL;
        lectureEnCours>>lePb->var[i].indice;//lecture du nom de la variable
        lectureEnCours>>lePb->var[i].nbValeurs;// lecture du nombre de valeurs prises
        lePb->var[i].Val= new int [lePb->var[i].nbValeurs];//Creation du tableau contenant les valeurs prise par une variable
        for(int j=0; j<lePb->var[i].nbValeurs; j++)
        {
            lePb->var[i].Val[j]= 0;
            lectureEnCours>>lePb->var[i].Val[j];//lecture des valeurs d une variable n
        }

   }
   lePb->NbTotContr= nbLignes - lePb->nbVar-1;//Permet de determiner le nombre de lignes contraintes


   lePb->Cpb= new Contraintes[lePb->NbTotContr];
   for(int k= 0; k<lePb->NbTotContr; k++)
    {
        lectureEnCours>>lePb->Cpb[k].indice;//Id de la contrainte
        lectureEnCours>>lePb->Cpb[k].nbContr;//Nb d entites dans cette contrainte
        lePb->Cpb[k].ListeContr = new int [lePb->Cpb[k].nbContr];
       for(int l= 0; l<lePb->Cpb[k].nbContr; l++)
        {
             lePb->Cpb[k].ListeContr[l]= 0;
             lectureEnCours>>lePb->Cpb[k].ListeContr[l];//Parcours de l'ensemble des contraintes
        }
    }
    // Contraintes Var
    int tab[lePb->NbTotContr][2];// Tab temporaire, case 1 indice de la regle, case 2 1 si present 0 si non present, case 3, nb de valeurs dans cette contrainte
    int m=0;
    int compteur=0;
    bool testFin =false;
    int k=0;

     for(int i= 0; i<lePb->nbVar; i++)
     {
       // cout<< "\n valeur: "<< lePb->var[i].indice<<endl;//Test Affichage tab
        for(int j= 0; j<lePb->NbTotContr; j++)
           {
                do
                {
                     if(lePb->Cpb[j].ListeContr[k]== lePb->var[i].indice)
                     {
                         tab[j][m]= lePb->Cpb[j].indice;
                         tab[j][m+1]= 1;
                         tab[j][m+2]=lePb->Cpb[j].nbContr;
                         testFin=true;
                         compteur++;//Nombre de contraintes dependant d'une variable, affichage
                     }
                    k++;
                }while(k<lePb->Cpb[j].nbContr && testFin == false);

                if(testFin==false)
                {
                    tab[j][m]= lePb->Cpb[j].indice;
                    tab[j][m+1]= 0;
                    tab[j][m+2]=lePb->Cpb[j].nbContr;
                }
                //cout<<" C est : "<<tab[j][m]<<" "<<tab[j][m+1]<<" "<<tab[j][m+2]<<endl;//Test Affichage Tab
                k=0;
                testFin=false;
            }
            //////////////// Structure implemenation de contraintes
                int a=0;
               for(int l=0; l<lePb->NbTotContr; l++)
                {
                    lePb->var[i].ListContrVar.push_back(vector<int>());
                    lePb->var[i].ListContrVar[a].push_back(tab[l][0]);

                    if(tab[l][1]== 1)
                    {
                         for(int b=0; b<lePb->Cpb[l].nbContr; b++)
                        {
                            if(lePb->Cpb[l].ListeContr[b]!= lePb->var[i].indice)
                            {
                                if(lePb->Cpb[l].indice==4 && b == 0)//Pour le cas de la contrainte de la somme, ListeContr[] contient uniquement des variables
                                {
                                }

                                else
                                {
                                    lePb->var[i].ListContrVar[a].push_back(lePb->Cpb[l].ListeContr[b]);//Affectation des contraintes et des variables avec lequelles elles dependent
                                }
                            }
                        }
                      }
                      a++;
                    }

        for(int l=0; l<lePb->NbTotContr; l++)
            {
                for(int n=0; n<3; n++)
                {
                    tab[l][n]= 0;//Remettre le tab temporaire a 0
                }
            }
            //cout<<"le compteur est: "<<compteur<<endl;//Test affichage Tab
            compteur=0;
     }
    return lePb;
}



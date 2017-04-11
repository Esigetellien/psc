#include <iostream>
#include "Structure.h"

using namespace std;

 void affichage(Pb* MonPb)
 {
     cout<<"\n \n====== Affichage =======\n"<<endl;
     cout<<"Nombre de Variables: "<< MonPb->nbVar<<endl;
     for (int i=0; i<MonPb->nbVar; i++)
     {
           cout<<"- Variable "<<MonPb->var[i].indice<<" possede "<<MonPb->var[i].nbValeurs<< " valeur(s): ";
           for(int j =0; j<MonPb->var[i].nbValeurs;j++)
           {
                cout<<MonPb->var[i].Val[j]<<"  ";
           }
           cout<<endl;
     }     cout<<endl;

    cout<<"----- Les contraintes -----\n"<<endl;
    cout<<"Il existe "<< MonPb->NbTotContr<<" contrainte(s): "<<endl;
    for (int i=0; i<MonPb->NbTotContr; i++)
     {
         switch (MonPb->Cpb[i].indice)
        {
        case 1:
            cout<<"- Variables egales: "<<endl;
            break;
         case 2:
            cout<<"- Variables differentes: "<<endl;
            break;
         case 3:
            cout<<"- Variable inferieure ou egale a une autre: "<<endl;
            break;
         case 4:
            cout<<"- Somme de variable egales a une valeur determinee: "<<endl;
            break;

        default: cout<<"Erreur de description"<<endl;
        break;
        }
        if(MonPb->Cpb[i].indice==4)
        {
            cout<<"La somme doit etre egale a "<<MonPb->Cpb[i].ListeContr[0]<<endl;
             for(int j=1;j<MonPb->Cpb[i].nbContr; j++)
            {
                cout<<" "<<MonPb->Cpb[i].ListeContr[j]<<" ";
            }
        }
        else
        {
            for(int j=0;j<MonPb->Cpb[i].nbContr; j++)
            {
                cout<<" "<<MonPb->Cpb[i].ListeContr[j]<<" ";
            }
        }

        cout<<endl;
     }
    cout<<"\n----- Dependance des variables -----"<<endl;
     for (int i=0; i<MonPb->nbVar; i++)
     {
         cout<<"\n\nLa Variable "<<MonPb->var[i].indice<<" possede: ";
         for(unsigned int j=0; j<MonPb->var[i].ListContrVar.size(); j++)
         {
           // cout<<"Taille 1: "<<MonPb->var[i].ListContrVar.size()<<endl;
            cout<<"\nLa contrainte "<<MonPb->var[i].ListContrVar[j][0]<<" avec les variables: ";
            for(unsigned int l=1;l<MonPb->var[i].ListContrVar[j].size();l++)
           {
             //  cout<<"Taille 2: "<<MonPb->var[i].ListContrVar[j].size()<<endl;
               cout<<" "<<MonPb->var[i].ListContrVar[j][l]<<" ";
           }
         }
         cout<<endl;
     }
 }

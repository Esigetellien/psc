#include <iostream>
#include "Structure.h"

using namespace std;

int main()
{
      int choix=0;
    //do
    //{
    system("cls");
    char MonF[] ="pb1.txt";//Supprimer cette ligne lorsque l on mettra en place les differents fichiers
    Pb* Monpb;
    cout << "---- Projet Aide a la Decision ----"<<endl;
    cout<< "---------- Solveur PSC --------------\n\n"<<endl;
    cout<<" Veuillez choisir le pb a resoudre: \n"<<endl;
    cout<< " 1. Le Sudoku\n 2. Le Sudoku avec la contrainte Somme\n 3. Le Crypt-arithmetique\n 4. Le Coloriage de carte\n 5. Le Coloriage de carte avec la contrainte d egalite\n 6. Grille triangulaire Superieure\n 7. Grille triangualire superieure avec contraintes\n 8. Quitter"<<endl;
    cout<< "\nVotre choix: ";
    Monpb= lecture(MonF);//Supprimer cette ligne lorsque l on mettra en place les differents fichiers
    affichage(Monpb);//Supprimer cette ligne lorsque l on mettra en place les differents fichiers
   /* cin>> choix;//faire saisie secu
    switch(choix)
    {
        case 1:
        {
            char MonF[] ="pb1.txt";
            Monpb= lecture(MonF);
            affichage(Monpb);
            break;
        }

        case 2:
        {
           char MonF[]="pb2.txt";
            Monpb= lecture(MonF);
            break;
        }

        case 3:
        {
            char MonF[] ="pb3.txt";
            Monpb= lecture(MonF);
            break;
        }

        case 4:
        {
            char MonF[] ="pb4.txt";
            Monpb= lecture(MonF);
            break;
        }

        case 5:
        {
           char MonF[] ="pb5.txt";
            Monpb= lecture(MonF);
            break;
        }

        case 6:
        {
           char MonF[] ="pb6.txt";
            Monpb= lecture(MonF);
            break;
        }

        case 7:
        {
            char MonF[] ="pb7.txt";
            Monpb= lecture(MonF);
            break;
        }

        case 8:
        {
            break;
        }

        default:
        {
            cout<<"\nErreur selection des fichiers"<<endl;
            break;
        }
    }
    system("PAUSE");
    }while(choix !=8);

    cout<<"\n\nProgramme developpe par Duhamel Gayraud Gouessant Laversanne Zuber"<<endl;*/
    return 0;
}

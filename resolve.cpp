#include <iostream>
#include "resolve.h"

void methodeTriviale(vector<Variable> variablesAssignees, Variable* variables, Contraintes* contraintes, Pb *probleme)
{
    /*
    for (int k = 0; k < variablesAssignees.size(); k++)
    {
        cout<<variablesAssignees[k].indice<< " : " << variablesAssignees[k].Val[0]<<endl;
    }
    cout<<endl;
    system("Pause");
    */
    int temp2;
    bool egal = true;
    if(variablesAssignees.size() == sizeof(variables) +1)
    {
        //cout<< "VARIABLES: " << sizeof(variables)<<endl;
        for (int k = 0; k < variablesAssignees.size(); k++)
        {
            if (!variablesAssignees[k].indice == variables[k].indice)
                return;
        }
    }
    else
        egal = false;

    if(egal)
    {

        if (verifContraintes(variablesAssignees, variables, contraintes, probleme))
        {
            cout<<"trace"<<endl;
            for (int k = 0; k < variablesAssignees.size(); k++)
            {
                cout<<variablesAssignees[k].indice<< " : " << variablesAssignees[k].Val[0];
            }
        }
        else
            return;
    }
    else
    {
        Variable tempVar;
        vector <Variable> tempVariableAssigne;

        for(int x = 0; x < variables[variablesAssignees.size()].nbValeurs; x++)
        {
            tempVar = variables[variablesAssignees.size()];
            //int tempTab = (variables[variablesAssignees.size()].Val[x]);
            tempVar.Val[0] = (variables[variablesAssignees.size()].Val[x]);

            tempVariableAssigne.clear();
            for(int j = 0; j < variablesAssignees.size(); j++)
            {
                tempVariableAssigne.push_back(variablesAssignees[j]);
            }
            tempVariableAssigne.push_back(tempVar);

            methodeTriviale(tempVariableAssigne, variables, contraintes, probleme);
        }
    }
}

bool verifContraintes(vector<Variable> variablesAssignees, Variable* variables, Contraintes* contraintes, Pb *MonPb)
{
    int temp;
    bool tempBool;

    for(int k = 0; k < variablesAssignees.size(); k++)
    {
        /*
        if(sizeof(variablesAssignees[k].Val) != 4)
        {
            cout<<"debug1"<<endl;
            return false;
        }
        */
        temp = variablesAssignees[k].Val[0];

        tempBool = false;
        for(int i = 0; i < sizeof(variables[k].Val); i ++)
        {
            if (temp == variables[k].Val[i])
                tempBool = true;
        }
        if (tempBool == false)
        {
            cout<<"debug2"<<endl;
            return false;
        }

    }

    for (int i=0; i<MonPb->NbTotContr; i++)
    {
         switch (MonPb->Cpb[i].indice)
        {
        case 1:
            //Variables egales
            for (int j = 0; j < MonPb->Cpb[i].nbContr; j++)
            {
                if(variablesAssignees[MonPb->Cpb[i].ListeContr[j]-1].Val[0] != variablesAssignees[MonPb->Cpb[i].ListeContr[0]-1].Val[0])
                {
                    cout<<"debug3"<<endl;
                    //cout<<MonPb->Cpb[i].ListeContr[j] << ":" << MonPb->Cpb[i].ListeContr[0] <<endl;
                    //cout<<variablesAssignees[MonPb->Cpb[i].ListeContr[j]-1].indice << "->" << variablesAssignees[MonPb->Cpb[i].ListeContr[0]-1].indice <<endl;
                    //cout<<variablesAssignees[MonPb->Cpb[i].ListeContr[j]-1].Val[0] << "=" << variablesAssignees[MonPb->Cpb[i].ListeContr[0]-1].Val[0] <<endl;
                    return false;
                }
            }
            break;
         case 2:
            //Variables differentes
            for (int j = 0; j < MonPb->Cpb[i].nbContr; j++)
            {
                if(variablesAssignees[MonPb->Cpb[i].ListeContr[j]-1].Val[0] == variablesAssignees[MonPb->Cpb[i].ListeContr[0]-1].Val[0])
                {
                    cout<<"debug4"<<endl;
                    return false;
                }

            }
            break;
         case 3:
            //Variable inferieure ou egale a une autre
            for (int j = 0; j < MonPb->Cpb[i].nbContr; j++)
            {
                if(variablesAssignees[MonPb->Cpb[i].ListeContr[j]-1].Val[0] <= variablesAssignees[MonPb->Cpb[i].ListeContr[0]-1].Val[0])
                {
                    cout<<"debug5"<<endl;
                    return false;
                }

            }
            break;
         case 4:
            //Somme de variable egales a une valeur determinee
            temp = 0;
            for (int j = 0; j < MonPb->Cpb[i].nbContr; j++)
            {
                temp += variablesAssignees[MonPb->Cpb[i].ListeContr[j]-1].Val[0];
            }
            if(temp != MonPb->Cpb[i].ListeContr[0])
            {
                cout<<"debug6"<<endl;
                return false;
            }

            break;

        default: cout<<"Erreur de description"<<endl;
        break;
        }
    }
    return true;
}

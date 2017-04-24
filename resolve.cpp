#include <iostream>
#include "resolve.h"

void methodeTriviale(vector<Variable> variablesAssignees, const Variable* variables, Contraintes* contraintes, const Pb *probleme)
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
        /*
        cout<< "VARIABLES: ";
        for (int i = 0; i < variablesAssignees.size(); i++)
        {
            cout << variablesAssignees[i].Val[0] << "  ";
        }
        cout<< endl;
        */

        if (verifContraintes(variablesAssignees, variables, contraintes, probleme))
        {
            cout<<"Resultat"<<endl;
            for (int k = 0; k < variablesAssignees.size(); k++)
            {
                cout<<variablesAssignees[k].indice<< " : " << variablesAssignees[k].Val[0] << endl;

            }
            return;
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
            //cout<<"trace1"<<endl;
            if (variablesAssignees.size() < sizeof(variables)+1)
            {
                tempVar = variables[variablesAssignees.size()];
                //int tempTab = (variables[variablesAssignees.size()].Val[x]);
                            //cout<<"trace2"<<endl;
                if(tempVar.nbValeurs != 0 && (variablesAssignees.size() < sizeof(variables)+1))
                    tempVar.Val[0] = (variables[variablesAssignees.size()].Val[x]);
                else
                    cout<<"erreur"<<endl;

                tempVariableAssigne.clear();
                            //cout<<"trace4"<<endl;

                for(int j = 0; j < variablesAssignees.size(); j++)
                {
                                //cout<<"trace5"<<endl;

                    tempVariableAssigne.push_back(variablesAssignees[j]);
                    //cout << "debug" << variablesAssignees[j].Val[0] << endl;
                }
                tempVariableAssigne.push_back(tempVar);

                methodeTriviale(tempVariableAssigne, variables, contraintes, probleme);
            }

        }
    }
}

bool verifContraintes(vector<Variable> variablesAssignees, const Variable* variables, Contraintes* contraintes, const Pb *MonPb)
{
    int temp;
    bool tempBool;
    int test1, test2;
    Variable variable1, variable2;

    //affichage(MonPb);

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
            //cout<<"debug2"<<endl;
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
                test1 = MonPb->Cpb[i].ListeContr[j];
                for (int k = 0; k < MonPb->Cpb[i].nbContr; k++)
                {
                    if(k != j)
                    {
                        test2 = MonPb->Cpb[i].ListeContr[k];
                        for (int var = 0; var < variablesAssignees.size(); var++)
                        {
                            if(variablesAssignees[var].indice == test1)
                            {
                                variable1 = variablesAssignees[var];
                            }
                            if(variablesAssignees[var].indice == test2)
                            {
                                variable2 = variablesAssignees[var];
                            }

                        }
                        //cout<<"debug"<< variable1.indice << " != " << variable2.indice << endl;
                        if(variable1.Val[0] !=  variable2.Val[0])
                        {


                            //cout<<"debug"<< variablesAssignees[MonPb->Cpb[i].ListeContr[j]-1].Val[0] << " != " << variablesAssignees[MonPb->Cpb[i].ListeContr[0]-1].Val[0] << endl;
                            //cout<<"debug"<< variablesAssignees[MonPb->Cpb[i].ListeContr[j]].indice << " != " << variablesAssignees[MonPb->Cpb[i].ListeContr[0]].indice << endl;
                            //cout<<MonPb->Cpb[i].ListeContr[j] << ":" << MonPb->Cpb[i].ListeContr[0] <<endl;
                            //cout<<variablesAssignees[MonPb->Cpb[i].ListeContr[j]-1].indice << "->" << variablesAssignees[MonPb->Cpb[i].ListeContr[0]-1].indice <<endl;
                            //cout<<variablesAssignees[MonPb->Cpb[i].ListeContr[j]-1].Val[0] << "=" << variablesAssignees[MonPb->Cpb[i].ListeContr[0]-1].Val[0] <<endl;
                            return false;
                        }
                        //else
                            //cout<<"debug 1" << endl;
                    }
                }
            }
            break;
         case 2:
            //Variables differentes
            for (int j = 0; j < MonPb->Cpb[i].nbContr; j++)
            {
                test1 = MonPb->Cpb[i].ListeContr[j];
                for (int k = 0; k < MonPb->Cpb[i].nbContr; k++)
                {
                    if(k != j)
                    {
                        test2 = MonPb->Cpb[i].ListeContr[k];
                        for (int var = 0; var < variablesAssignees.size(); var++)
                        {
                            if(variablesAssignees[var].indice == test1)
                            {
                                variable1 = variablesAssignees[var];
                            }
                            if(variablesAssignees[var].indice == test2)
                            {
                                variable2 = variablesAssignees[var];
                            }

                        }
                        //cout<<"debug"<< variable1.indice << " != " << variable2.indice << endl;

                        if(variable1.Val[0] ==  variable2.Val[0] && variable1.indice !=  variable2.indice)
                        {
                            //cout<<"debug"<< variable1.indice << " != " << variable2.indice << endl;
                            //cout<<"debug"<< variablesAssignees[MonPb->Cpb[i].ListeContr[j]].indice << " != " << variablesAssignees[MonPb->Cpb[i].ListeContr[0]].indice << endl;
                            //cout<<MonPb->Cpb[i].ListeContr[j] << ":" << MonPb->Cpb[i].ListeContr[0] <<endl;
                            //cout<<variablesAssignees[MonPb->Cpb[i].ListeContr[j]-1].indice << "->" << variablesAssignees[MonPb->Cpb[i].ListeContr[0]-1].indice <<endl;
                            //cout<<variablesAssignees[MonPb->Cpb[i].ListeContr[j]-1].Val[0] << "=" << variablesAssignees[MonPb->Cpb[i].ListeContr[0]-1].Val[0] <<endl;
                            return false;
                        }
                        //else
                            //cout<<"debug 2" << endl;
                    }
                }
            }
            break;
         case 3:
            //Variable inferieure ou egale a une autre
            for (int j = 0; j < MonPb->Cpb[i].nbContr; j++)
            {
                test1 = MonPb->Cpb[i].ListeContr[j];
                for (int k = 0; k < MonPb->Cpb[i].nbContr; k++)
                {
                    if(k != j)
                    {
                        test2 = MonPb->Cpb[i].ListeContr[k];
                        for (int var = 0; var < variablesAssignees.size(); var++)
                        {
                            if(variablesAssignees[var].indice == test1)
                            {
                                variable1 = variablesAssignees[var];
                            }
                            if(variablesAssignees[var].indice == test2)
                            {
                                variable2 = variablesAssignees[var];
                            }

                        }
                        //cout<<"debug"<< variable1.indice << " != " << variable2.indice << endl;
                        if(variable1.Val[0] >  variable2.Val[0] )
                        {
                            //cout<<"debug"<< variable1.indice << " != " << variable2.indice << endl;
                            //cout<<"debug"<< variablesAssignees[MonPb->Cpb[i].ListeContr[j]-1].Val[0] << " != " << variablesAssignees[MonPb->Cpb[i].ListeContr[0]-1].Val[0] << endl;
                            //cout<<"debug"<< variablesAssignees[MonPb->Cpb[i].ListeContr[j]].indice << " != " << variablesAssignees[MonPb->Cpb[i].ListeContr[0]].indice << endl;
                            //cout<<MonPb->Cpb[i].ListeContr[j] << ":" << MonPb->Cpb[i].ListeContr[0] <<endl;
                            //cout<<variablesAssignees[MonPb->Cpb[i].ListeContr[j]-1].indice << "->" << variablesAssignees[MonPb->Cpb[i].ListeContr[0]-1].indice <<endl;
                            //cout<<variablesAssignees[MonPb->Cpb[i].ListeContr[j]-1].Val[0] << "=" << variablesAssignees[MonPb->Cpb[i].ListeContr[0]-1].Val[0] <<endl;
                            return false;
                        }
                        else
                        {
                            j = MonPb->Cpb[i].nbContr;
                            k = MonPb->Cpb[i].nbContr;
                        }
                            //cout<<"debug 3" << endl;
                    }
                }
            }
            break;
         case 4:
            //Somme de variable egales a une valeur determinee
            temp = 0;
            //cout<<"debug ";
            //cout << "debug ";
            for (int j = 1; j < MonPb->Cpb[i].nbContr; j++)
            {
                test1 = MonPb->Cpb[i].ListeContr[j];

                for (int var = 0; var < variablesAssignees.size(); var++)
                {
                    if(variablesAssignees[var].indice == test1)
                    {

                        variable1 = variablesAssignees[var];
                    }
                }
                temp += variable1.Val[0];
                //cout << " + " << variable1.indice;
                //cout << variablesAssignees[MonPb->Cpb[i].ListeContr[j]-1].Val[0] << " + ";
            }
            //cout << endl;
            if(temp != MonPb->Cpb[i].ListeContr[0])
            {
                //cout<<" != "<< MonPb->Cpb[i].ListeContr[0] << endl;
                //cout<<"debug6"<<endl;
                return false;
            }
            else
                cout<<"debug 4" << endl;
            //cout <<endl;
            break;

        //default: cout<<"Erreur de description"<<endl;
        break;
        }
    }
    return true;
}

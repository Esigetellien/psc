#ifndef RESOLVE_H_INCLUDED
#define RESOLVE_H_INCLUDED

#include "Structure.h"

using namespace std;

void methodeTriviale(vector<Variable> variablesAssignees, Variable* variables, Contraintes* contraintes, Pb *probleme);
bool verifContraintes(vector<Variable> variablesAssignees, Variable* variables, Contraintes* contraintes, Pb *probleme);

#endif // RESOLVE_H_INCLUDED

#ifndef RESOLVE_H_INCLUDED
#define RESOLVE_H_INCLUDED

#include "Structure.h"

using namespace std;

void methodeTriviale(vector<Variable> variablesAssignees, const Variable* variables, Contraintes* contraintes, const Pb *probleme);
bool verifContraintes(vector<Variable> variablesAssignees, const Variable* variables, Contraintes* contraintes, const Pb *probleme);

#endif // RESOLVE_H_INCLUDED

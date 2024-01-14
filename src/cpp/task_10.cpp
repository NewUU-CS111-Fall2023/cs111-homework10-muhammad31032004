/*
 * Author: Mukhammadkhon Asrorov
 * Date: 14/01/2024
 * Name: hw-10
 */

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

string generate3SATFormula(int numVariables, int numClauses) {
    string formula;

    srand(static_cast<unsigned int>(time(0)));

    for (int i = 0; i < numClauses; ++i) {
        string clause;

        for (int j = 0; j < 3; ++j) {
            char variable = 'A' + rand() % numVariables;
            bool negate = rand() % 2 == 0;

            if (negate) {
                clause += "~";
            }

            clause += variable;

            if (j < 2) {
                clause += " | ";
            }
        }

        formula += "(" + clause + ")";

        if (i < numClauses - 1) {
            formula += " & ";
        }
    }

    return formula;
}

int main() {
    int numVariables = 3;
    int numClauses = 2;
  
    string formula = generate3SATFormula(numVariables, numClauses);

    cout << "Generated 3-SAT formula: " << formula << endl;

    return 0;
}

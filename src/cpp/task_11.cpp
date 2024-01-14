/*
 * Author: Mukhammadkhon Asrorov 
 * Date: 14/01/2024
 * Name: hw-10
 */

#include <iostream>
#include <vector>

using namespace std;

bool solveSAT(const vector<vector<int>>& cnf_formula) {
    int num_variables = 0;

    for (const auto& clause : cnf_formula) {
        for (int literal : clause) {
            int variable = abs(literal);
            num_variables = max(num_variables, variable);
        }
    }

    for (int i = 0; i < (1 << num_variables); ++i) {
        vector<bool> assignment(num_variables + 1, false);

        for (int j = 1; j <= num_variables; ++j) {
            assignment[j] = (i & (1 << (j - 1))) != 0;
        }

        bool is_satisfied = true;

        for (const auto& clause : cnf_formula) {
            bool clause_satisfied = false;

            for (int literal : clause) {
                int variable = abs(literal);
                bool value = (literal > 0) ? assignment[variable] : !assignment[variable];

                clause_satisfied |= value;
            }

            is_satisfied &= clause_satisfied;
        }

        if (is_satisfied) {
            return true;
        }
    }

    return false;
}

int main() {
    vector<vector<int>> cnf_formula1 = {{1, 2, -3}, {-1, -2, 3}, {2, -3}};
    vector<vector<int>> cnf_formula2 = {{1, 2}, {-1, 3}, {-2, -3}};
    vector<vector<int>> cnf_formula3 = {{1, 2, 3}, {-1, -2, 3}, {1, -3}};
    vector<vector<int>> cnf_formula4 = {{1, 2}, {-1, -2}, {1, -2}};

    cout << "SAT Formula 1: " << (solveSAT(cnf_formula1) ? "True" : "False") << endl;
    cout << "SAT Formula 2: " << (solveSAT(cnf_formula2) ? "True" : "False") << endl;
    cout << "SAT Formula 3: " << (solveSAT(cnf_formula3) ? "True" : "False") << endl;
    cout << "SAT Formula 4: " << (solveSAT(cnf_formula4) ? "True" : "False") << endl;

    return 0;
}

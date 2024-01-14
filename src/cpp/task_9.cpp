/*
 * Author: Mukhammadkhon Asrorov
 * Date: 14/01/2024
 * Name: hw-10
 */

#include <iostream>
#include <unordered_map>
#include <stack>

using namespace std;

bool evaluateFormula(const string& formula, const unordered_map<char, bool>& assignment) {
    stack<bool> resultStack;

    for (char ch : formula) {
        if (isalpha(ch)) {
            resultStack.push(assignment.at(ch));
        } else if (ch == '~') {
            bool operand = resultStack.top();
            resultStack.pop();
            resultStack.push(!operand);
        } else if (ch == '|') {
            bool operand2 = resultStack.top();
            resultStack.pop();
            bool operand1 = resultStack.top();
            resultStack.pop();
            resultStack.push(operand1 || operand2);
        } else if (ch == '&') {
            bool operand2 = resultStack.top();
            resultStack.pop();
            bool operand1 = resultStack.top();
            resultStack.pop();
            resultStack.push(operand1 && operand2);
        }
    }

    return resultStack.top();
}

int main() {
    string formula = "(A | ~B) & (~A | B | C)";
    unordered_map<char, bool> assignment = {{'A', true}, {'B', false}, {'C', true}};

    bool result = evaluateFormula(formula, assignment);

    cout << (result ? "Satisfied" : "Not Satisfied") << endl;

    return 0;
}

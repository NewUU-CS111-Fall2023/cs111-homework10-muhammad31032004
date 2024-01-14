/*
 * Author: Mukhammadkhon Asrorov
 * Date: 14/01/2024
 * Name: hw-10
 */

#include <iostream>
#include <vector>

using namespace std;

enum State {
    Q0,  
    Q1,  
    Q2,  
    Q3,  
    Q4,  
    Q5   
};

void compareNumbers(string& tape) {
    State currentState = Q0;
    int head = 0;

    while (currentState != Q5) {
        char currentSymbol = tape[head];

        switch (currentState) {
            case Q0:
                if (currentSymbol == '0') {
                    head++;
                    currentState = Q1;
                } else {
                    currentState = Q5;  // Invalid input
                }
                break;

            case Q1:
                if (currentSymbol == '1' || currentSymbol == 'c') {
                    head++;
                } else if (currentSymbol == ' ') {
                    head--;
                    currentState = Q3;
                }
                break;

            case Q2:
                if (currentSymbol == '1' || currentSymbol == 'c') {
                    head++;
                } else if (currentSymbol == '0') {
                    head--;
                    currentState = Q3;
                }
                break;

            case Q3:
                if (currentSymbol == '1' || currentSymbol == '0' || currentSymbol == 'c') {
                    head--;
                } else if (currentSymbol == ' ') {
                    head++;
                    currentState = Q4;
                }
                break;

            case Q4:
                if (currentSymbol == '1') {
                    tape[head] = '1';
                    head++;
                } else if (currentSymbol == '0') {
                    tape[head] = '0';
                    head++;
                } else if (currentSymbol == 'c') {
                    head++;
                    currentState = Q2;
                } else if (currentSymbol == ' ') {
                    head++;
                    currentState = Q5;
                }
                break;

            case Q5:
                // End of the tape
                break;
        }
    }
}

int main() {
    string tape = "0 1 1 1 c 1 1 1 1 0";

    compareNumbers(tape);

    cout << "Result: " << tape << endl;

    return 0;
}

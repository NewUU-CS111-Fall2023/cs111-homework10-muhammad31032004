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

void unaryAddition(string& tape) {
    State currentState = Q0;
    int head = 0;

    while (currentState != Q5) {
        char currentSymbol = tape[head];

        switch (currentState) {
            case Q0:
                if (currentSymbol == '1') {
                    currentState = Q1;
                } else {
                    currentState = Q5;
                }
                break;

            case Q1:
                if (currentSymbol == '1') {
                    head++;
                } else if (currentSymbol == '0') {
                    tape[head] = 'X';
                    head--;
                    currentState = Q2;
                }
                break;

            case Q2:
                if (currentSymbol == '1') {
                    head--;
                } else if (currentSymbol == 'X') {
                    head++;
                    currentState = Q3;
                }
                break;

            case Q3:
                if (currentSymbol == '1' || currentSymbol == 'X') {
                    head++;
                } else if (currentSymbol == ' ') {
                    head--;
                    currentState = Q4;
                }
                break;

            case Q4:
                if (currentSymbol == 'X') {
                    head--;
                } else if (currentSymbol == ' ') {
                    head++;
                    currentState = Q5;
                }
                break;

            case Q5:
                break;
        }
    }
}

int main() {
    string number1 = "1111";  // Representing 4 in unary
    string number2 = "111";   // Representing 3 in unary

    string tape = number1 + "0" + number2 + " ";

    unaryAddition(tape);

    cout << "Result: " << tape << endl;

    return 0;
}

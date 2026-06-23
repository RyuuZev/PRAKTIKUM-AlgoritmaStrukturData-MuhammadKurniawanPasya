#include <iostream>
#include <string>
#include "stack.h"

using namespace std;

bool isOperator(const string& s) {
    return (s == "+" || s == "-" || s == "*" || s == "/");
}

int main() {
    int n;
    if (!(cin >> n)) return 0;

    Stack s;
    init(&s);

    for (int i = 0; i < n; ++i) {
        string simbol;
        cin >> simbol;

        if (isOperator(simbol)) {
            int operand2 = peek(&s); pop(&s);
            int operand1 = peek(&s); pop(&s);
            int hasil;

            if (simbol == "+") hasil = operand1 + operand2;
            else if (simbol == "-") hasil = operand1 - operand2;
            else if (simbol == "*") hasil = operand1 * operand2;
            else if (simbol == "/") {
                if (operand2 == 0) return 1; 
                hasil = operand1 / operand2;
            }

            push(&s, hasil);
        } 
        else {
            push(&s, stoi(simbol));
        }
    }

    cout << peek(&s) << endl;

    return 0;
}
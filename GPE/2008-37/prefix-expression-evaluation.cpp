#include <iostream>
#include <sstream>
#include <stack>
#include <vector>
using namespace std;

bool isNumber(const string& s) {
    for (char c : s) {
        if (isdigit(c) == false) {
            return false;
        }
    }
    return true;
}

bool isOperator(const string& s) {
    return s == "+" || s == "-" || s == "*" || s == "/" || s == "%";
}

int operate(const string& op, int a, int b) {
    if (op == "+") {
        return a + b;
    }
    if (op == "-") {
        return a - b;
    }
    if (op == "*") {
        return a * b;
    }
    if (op == "/") {
        return a / b;
    }
    if (op == "%") {
        return a % b;
    }

    return 0;
}

int main() {
    string s;

    while (getline(cin, s) && s != ".") {
        stringstream ss(s);
        string token;
        vector<string> tokens;

        while (ss >> token) {
            tokens.push_back(token);
        }

        stack<int> operands;
        bool isValid = true;

        for (int i = tokens.size() - 1; i >= 0; --i) {
            if (isNumber(tokens[i]) == true) {
                operands.push(stoi(tokens[i]));
            } else if (isOperator(tokens[i]) == true) {
                if (operands.size() < 2) {
                    isValid = false;

                    break;
                }

                int a = operands.top();
                operands.pop();
                int b = operands.top();
                operands.pop();

                if ((tokens[i] == "/" || tokens[i] == "%") && b == 0) {
                    isValid = false;

                    break;
                }

                int result = operate(tokens[i], a, b);
                operands.push(result);
            }
        }

        if (isValid == false || operands.size() > 1) {
            cout << "illegal" << endl;
        } else {
            cout << operands.top() << endl;
        }
    }

    return 0;
}

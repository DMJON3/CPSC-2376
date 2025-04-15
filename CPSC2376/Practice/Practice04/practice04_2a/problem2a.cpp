#include <iostream>
#include <sstream>
using namespace std;

template <typename T>
T calculate(T a, T b, char op) {
    switch (op) {
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    case '/': return b != 0 ? a / b : 0;
    default:
        cout << "Invalid operator.\n";
        return 0;
    }
}

bool isDecimal(const string& s) {
    return s.find('.') != string::npos;
}

int main() {
    string input1, input2;
    char op;

    cout << "Enter first number: ";
    cin >> input1;

    cout << "Enter second number: ";
    cin >> input2;

    cout << "Enter operation (+, -, *, /): ";
    cin >> op;

    if (isDecimal(input1) || isDecimal(input2)) {
        double a = stod(input1);
        double b = stod(input2);
        double result = calculate<double>(a, b, op);
        cout << "Result: " << result << endl;
    }
    else {
        int a = stoi(input1);
        int b = stoi(input2);
        int result = calculate<int>(a, b, op);
        cout << "Result: " << result << endl;
    }

    return 0;
}

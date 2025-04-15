#include <iostream>
using namespace std;


double convertTemperature(double temp, char scale = 'F') {
    if (scale == 'F') {

        return (temp * 9.0 / 5.0) + 32.0;
    }
    else if (scale == 'C') {

        return (temp - 32.0) * 5.0 / 9.0;
    }
    else {
        cout << "Invalid scale. Use 'F' or 'C'.\n";
        return temp;
    }
}

int main() {
    int choice;
    double inputTemp, resultTemp;

    cout << "1. Convert Celsius to Fahrenheit\n";
    cout << "2. Convert Fahrenheit to Celsius\n";
    cout << "Choose an option: ";
    cin >> choice;

    if (choice == 1) {
        cout << "Enter temperature in Celsius: ";
        cin >> inputTemp;
        resultTemp = convertTemperature(inputTemp, 'F');
        cout << "Converted: " << resultTemp << "°F\n";
    }
    else if (choice == 2) {
        cout << "Enter temperature in Fahrenheit: ";
        cin >> inputTemp;
        resultTemp = convertTemperature(inputTemp, 'C');
        cout << "Converted: " << resultTemp << "°C\n";
    }
    else {
        cout << "Invalid option selected.\n";
    }

    return 0;
}

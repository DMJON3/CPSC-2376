#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    const string FILENAME = "account_balance.txt";
    double balance = 0.0;

    // Open the file to read balance
    ifstream infile(FILENAME);
    if (!infile.is_open()) {
        // File doesn't exist, create it with default balance
        ofstream outfile(FILENAME);
        if (!outfile.is_open()) {
            cerr << "Error: Unable to create balance file." << endl;
            return 1;
        }
        balance = 100.0;
        outfile << balance;
        outfile.close();
        cout << "New account created with initial balance: $100.00\n";
    }
    else {
        infile >> balance;
        infile.close();
        cout << "Account loaded. Current balance: $" << balance << "\n";
    }

    int choice;
    while (true) {
        cout << "\n=== Menu ===\n";
        cout << "1. Check Balance\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear(); // Clear the error
            cin.ignore(1000, '\n'); // Discard invalid input
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        if (choice == 1) {
            cout << "Current balance: $" << balance << "\n";
        }
        else if (choice == 2) {
            double amount;
            cout << "Enter amount to deposit: $";
            cin >> amount;

            if (cin.fail() || amount <= 0) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Deposit must be a positive number.\n";
                continue;
            }

            balance += amount;
            ofstream outfile(FILENAME);
            outfile << balance;
            outfile.close();
            cout << "Deposited: $" << amount << "\n";
        }
        else if (choice == 3) {
            double amount;
            cout << "Enter amount to withdraw: $";
            cin >> amount;

            if (cin.fail() || amount <= 0) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Withdrawal must be a positive number.\n";
                continue;
            }

            if (amount > balance) {
                cout << "Insufficient funds. Your balance is $" << balance << "\n";
            }
            else {
                balance -= amount;
                ofstream outfile(FILENAME);
                outfile << balance;
                outfile.close();
                cout << "Withdrew: $" << amount << "\n";
            }
        }
        else if (choice == 4) {
            cout << "Thank you for using the program. Goodbye!\n";
            break;
        }
        else {
            cout << "Invalid option. Please choose 1 to 4.\n";
        }
    }

    return 0;
}

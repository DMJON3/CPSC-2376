#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main() {
    deque<string> edits;
    int choice;
    string input;

    while (true) {
        cout << "\n1. Add Text\n";
        cout << "2. Undo Last Edit\n";
        cout << "3. Show Content\n";
        cout << "4. Exit\n";
        cout << "Choice: ";
        cin >> choice;
        cin.ignore(); 

        if (choice == 1) {
            cout << "Enter text: ";
            getline(cin, input);
            edits.push_back(input);
        }
        else if (choice == 2) {
            if (!edits.empty()) {
                edits.pop_back();
                cout << "Undo successful!\n";
            }
            else {
                cout << "Nothing to undo.\n";
            }
        }
        else if (choice == 3) {
            cout << "Current Content: ";
            for (const string& part : edits) {
                cout << part << " ";
            }
            cout << endl;
        }
        else if (choice == 4) {
            cout << "Exiting...\n";
            break;
        }
        else {
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}

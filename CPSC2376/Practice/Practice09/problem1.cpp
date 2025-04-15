#include <iostream>
#include <string>

using namespace std;

int main() {
    
    float redPotion{ 0.0f };   
    float bluePotion{ 0.0f }; 
    float* flask{ nullptr };   

    string potionChoice;
    float amountToAdd;

    while (true) {
 
        cout << "Which potion to add liquid to (Red, Blue, or Done to quit)? ";
        cin >> potionChoice;

        if (potionChoice == "Done" || potionChoice == "done") {
            break;
        }

        if (potionChoice == "Red" || potionChoice == "red") {
            flask = &redPotion;
        }
        else if (potionChoice == "Blue" || potionChoice == "blue") {
            flask = &bluePotion;
        }
        else {
            cout << "Invalid potion choice. Please type 'Red' or 'Blue'.\n";
            continue;
        }

        cout << "How many milliliters to add: ";
        cin >> amountToAdd;

        if (flask != nullptr) {
            *flask += amountToAdd;
        }

        cout << "Red potion: " << redPotion << " mL\n";
        cout << "Blue potion: " << bluePotion << " mL\n";
    }

    cout << "Brewing complete!\n";

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

int main() {
    vector<int> numbers;
    int n, value;

    cout << "How many numbers will you enter? ";
    cin >> n;

   
    cout << "Enter " << n << " integers:\n";
    for (int i = 0; i < n; ++i) {
        cin >> value;
        numbers.push_back(value);
    }

  
    if (!numbers.empty()) {
       
        vector<int>::iterator maxIt = max_element(numbers.begin(), numbers.end());
      
        vector<int>::iterator minIt = min_element(numbers.begin(), numbers.end());

        cout << "Largest element: " << *maxIt << endl;
        cout << "Smallest element: " << *minIt << endl;
    }
    else {
        cout << "The list is empty. No elements to compare.\n";
    }

    return 0;
}

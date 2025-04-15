#include <iostream>
#include <vector>

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

    
    cout << "\nNumbers in the same order:\n";
    for (vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

   
    int evenSum = 0;
    for (vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) {
        if (*it % 2 == 0) {
            evenSum += *it;
        }
    }

    cout << "Sum of even numbers: " << evenSum << endl;

    return 0;
}

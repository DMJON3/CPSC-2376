#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

int main() {
    vector<int> numbers;
    int n, value, threshold;

    cout << "How many numbers will you enter? ";
    cin >> n;
    cout << "Enter " << n << " integers:\n";
    for (int i = 0; i < n; ++i) {
        cin >> value;
        numbers.push_back(value);
    }

    cout << "Enter the threshold value: ";
    cin >> threshold;

    int countGreaterThanThreshold = count_if(numbers.begin(), numbers.end(),
        [threshold](int num) { return num > threshold; });

    cout << "Count of numbers greater than " << threshold << ": " << countGreaterThanThreshold << endl;

    auto newEnd = remove_if(numbers.begin(), numbers.end(),
        [threshold](int num) { return num < threshold; });

    numbers.erase(newEnd, numbers.end());

    cout << "Modified list (values >= threshold): ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

#include <iostream>
#include <vector>
#include <limits>

void printVector(const std::vector<int>& vec);
void doubleVector(std::vector<int>& vec);
int calculateSum(const std::vector<int>& vec);
void printMultiples(const std::vector<int>& vec, int multiple);

int main() {
    std::vector<int> numbers;
    int choice = 0;

    while (true) {
        std::cout << "\nMenu:\n";
        std::cout << "1. Add an item to the vector\n";
        std::cout << "2. Print the vector\n";
        std::cout << "3. Double the vector\n";
        std::cout << "4. Find the sum of the vector\n";
        std::cout << "5. Print multiples of a number\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter your choice (1-6): ";
        std::cin >> choice;


        if (std::cin.fail() || choice < 1 || choice > 6) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid choice, please try again.\n";
            continue;
        }

        switch (choice) {
        case 1: {
            int num;
            std::cout << "Enter a number to add to the vector: ";
            std::cin >> num;
            numbers.push_back(num);
            break;
        }
        case 2:
            printVector(numbers);
            break;
        case 3:
            doubleVector(numbers);
            std::cout << "The vector has been doubled.\n";
            break;
        case 4:
            std::cout << "The sum of the vector is: " << calculateSum(numbers) << "\n";
            break;
        case 5: {
            int multiple;
            std::cout << "Enter the number to print multiples of: ";
            std::cin >> multiple;
            printMultiples(numbers, multiple);
            break;
        }
        case 6:
            std::cout << "Exiting the program...\n";
            return 0;
        }
    }

    return 0;
}

void printVector(const std::vector<int>& vec) {
    if (vec.empty()) {
        std::cout << "The vector is empty.\n";
        return;
    }
    std::cout << "Vector contents: ";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec.at(i) << " ";
    }
    std::cout << "\n";
}

void doubleVector(std::vector<int>& vec) {
    for (size_t i = 0; i < vec.size(); ++i) {
        vec.at(i) *= 2;
    }
}

int calculateSum(const std::vector<int>& vec) {
    int sum = 0;
    for (size_t i = 0; i < vec.size(); ++i) {
        sum += vec.at(i);
    }
    return sum;
}

void printMultiples(const std::vector<int>& vec, int multiple) {
    bool found = false;
    std::cout << "Multiples of " << multiple << ": ";
    for (size_t i = 0; i < vec.size(); ++i) {
        if (vec.at(i) % multiple == 0) {
            std::cout << vec.at(i) << " ";
            found = true;
        }
    }
    if (!found) {
        std::cout << "None found.\n";
    }
    else {
        std::cout << "\n";
    }
}
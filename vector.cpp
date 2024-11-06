#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<int> numbers;  // Declare a vector of integers
    // Adding elements to the vector
    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);
    // Accessing elements using a loop
    cout << "Vector elements: ";
    for (int i = 0; i < numbers.size(); i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;
    // Removing the last element
    numbers.pop_back();
    // Displaying after removal
    cout << "After pop_back: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
#include <iostream>
#include <set>

using namespace std;

int main() {
    set<int> mySet;

    // Inserting elements
    mySet.insert(30);
    mySet.insert(10);
    mySet.insert(20);
    mySet.insert(20);  // Duplicates are not allowed

    // Displaying elements (sorted automatically)
    cout << "Set elements: ";
    for (int elem : mySet) {
        cout << elem << " ";
    }
    cout << endl;

    // Check if an element exists
    if (mySet.find(10) != mySet.end()) {
        cout << "10 is in the set." << endl;
    } else {
        cout << "10 is not in the set." << endl;
    }

    return 0;
}

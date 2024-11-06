#include <iostream>
#include <list>

using namespace std;

int main() {
    list<int> myList;

    // Inserting elements at the back and front
    myList.push_back(10);
    myList.push_back(20);
    myList.push_front(5);

    // Displaying the list
    cout << "List elements: ";
    for (auto it = myList.begin(); it != myList.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // Removing the first element
    myList.pop_front();

    // Displaying after removal
    cout << "After pop_front: ";
    for (int x : myList) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Item {
    int code;
    string name;
};

// Function to display items
void displayItems(const vector<Item>& items) {
    for (const auto& item : items) {
        cout << "Code: " << item.code << ", Name: " << item.name << endl;
    }
}

int main() {
    vector<Item> items = {
        {101, "Apple"},
        {102, "Banana"},
        {103, "Cherry"}
    };

    cout << "Items before sorting:" << endl;
    displayItems(items);

    // Sort items by code
    sort(items.begin(), items.end(), [](const Item& a, const Item& b) {
        return a.code < b.code;
    });

    cout << "\nItems after sorting by code:" << endl;
    displayItems(items);

    // Search for an item by code
    int searchCode;
    cout << "\nEnter item code to search: ";
    cin >> searchCode;

    auto it = find_if(items.begin(), items.end(), [searchCode](const Item& item) {
        return item.code == searchCode;
    });

    if (it != items.end()) {
        cout << "Item found: Code: " << it->code << ", Name: " << it->name << endl;
    } else {
        cout << "Item not found." << endl;
    }

    return 0;
}


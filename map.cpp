#include <iostream>
#include <map>

using namespace std;

int main() {
    map<string, int> ageMap;

    // Inserting key-value pairs
    ageMap["Alice"] = 25;
    ageMap["Bob"] = 30;
    ageMap["Charlie"] = 20;

    // Displaying key-value pairs
    cout << "Map contents:" << endl;
    for (auto it = ageMap.begin(); it != ageMap.end(); ++it) {
        cout << it->first << ": " << it->second << endl;
    }

    // Accessing value by key
    cout << "Age of Alice: " << ageMap["Alice"] << endl;

    return 0;
}

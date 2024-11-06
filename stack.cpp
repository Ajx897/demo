#include <iostream>
#include <stack>

using namespace std;

int main() {
    stack<int> s;

    // Pushing elements onto the stack
    s.push(10);
    s.push(20);
    s.push(30);

    // Displaying and popping elements from the stack
    while (!s.empty()) {
        cout << "Top element: " << s.top() << endl;
        s.pop();
    }

    return 0;
}

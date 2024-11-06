#include <iostream>
#include <queue>

using namespace std;

int main() {
    queue<int> q;

    // Enqueuing elements
    q.push(10);
    q.push(20);
    q.push(30);

    // Displaying the front and removing elements
    while (!q.empty()) {
        cout << "Front element: " << q.front() << endl;
        q.pop();
    }

    return 0;
}

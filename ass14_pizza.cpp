#include <iostream>
using namespace std;

class PizzaParlor {
private:
    int front, rear;
    int maxOrders;  // Maximum number of orders (capacity of the circular queue)
    int *queue;     // Dynamic array to hold the orders
    int count;      // To keep track of the current number of orders

public:
    // Constructor to initialize the queue
    PizzaParlor(int size) {
        maxOrders = size;
        queue = new int[maxOrders];
        front = rear = -1;
        count = 0;
    }

    // Destructor to free dynamically allocated memory
    ~PizzaParlor() {
        delete[] queue;
    }

    // Function to add a new order
    void addOrder(int orderID) {
        if ((rear + 1) % maxOrders == front) {
            cout << "Pizza Parlor is full! Cannot accept more orders." << endl;
            return;
        }

        // For the first order
        if (front == -1) {
            front = 0;
        }

        rear = (rear + 1) % maxOrders;
        queue[rear] = orderID;
        count++;
        cout << "Order " << orderID << " added successfully!" << endl;
    }

    // Function to serve (remove) an order
    void serveOrder() {
        if (front == -1) {
            cout << "No orders to serve!" << endl;
            return;
        }

        cout << "Order " << queue[front] << " is being served." << endl;
        if (front == rear) {
            // If the queue becomes empty after serving
            front = rear = -1;
        } else {
            front = (front + 1) % maxOrders;
        }
        count--;
    }

    // Function to display all the current orders in the queue
    void displayOrders() {
        if (front == -1) {
            cout << "No current orders in the queue!" << endl;
            return;
        }

        cout << "Current orders in the queue: ";
        int i = front;
        while (i != rear) {
            cout << queue[i] << " ";
            i = (i + 1) % maxOrders;
        }
        cout << queue[rear] << endl; // Print the last element
    }
};

// Main function to demonstrate the circular queue simulation
int main() {
    int maxOrders;
    cout << "Enter the maximum number of orders the pizza parlor can accept: ";
    cin >> maxOrders;

    PizzaParlor pizzaParlor(maxOrders);

    int choice, orderID;
    do {
        cout << "\nPizza Parlor Menu:\n";
        cout << "1. Add Order\n";
        cout << "2. Serve Order\n";
        cout << "3. Display Orders\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Order ID to add: ";
                cin >> orderID;
                pizzaParlor.addOrder(orderID);
                break;
            case 2:
                pizzaParlor.serveOrder();
                break;
            case 3:
                pizzaParlor.displayOrders();
                break;
            case 4:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice! Please enter a valid option." << endl;
        }
    } while (choice != 4);

    return 0;
}

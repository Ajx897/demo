#include <iostream>
#include <queue>
#include <string>

using namespace std;

// Function to add a job to the job queue
void addJob(queue<string> &jobQueue, string job) {
    jobQueue.push(job);
    cout << "Job '" << job << "' has been added to the queue." << endl;
}

// Function to delete a job from the job queue
void deleteJob(queue<string> &jobQueue) {
    if (jobQueue.empty()) {
        cout << "The job queue is empty. No jobs to delete." << endl;
    } else {
        cout << "Job '" << jobQueue.front() << "' has been processed and removed from the queue." << endl;
        jobQueue.pop();
    }
}

// Function to display the current job queue
void displayQueue(queue<string> jobQueue) {
    if (jobQueue.empty()) {
        cout << "The job queue is empty." << endl;
        return;
    }

    cout << "Current Job Queue: ";
    while (!jobQueue.empty()) {
        cout << jobQueue.front() << " ";
        jobQueue.pop();
    }
    cout << endl;
}

int main() {
    queue<string> jobQueue;
    int choice;
    string job;

    do {
        cout << "\nJob Queue Menu:" << endl;
        cout << "1. Add Job" << endl;
        cout << "2. Delete Job" << endl;
        cout << "3. Display Job Queue" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter job name: ";
                cin >> job;
                addJob(jobQueue, job);
                break;
            case 2:
                deleteJob(jobQueue);
                break;
            case 3:
                displayQueue(jobQueue);
                break;
            case 4:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}

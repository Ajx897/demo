#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    // Step 1: Create and write to an output file
    ofstream outputFile("example.txt");
    if (!outputFile) {
        cerr << "Error creating output file." << endl;
        return 1;
    }

    // Writing some information to the file
    outputFile << "Hello, world!" << endl;
    outputFile << "This is a test file." << endl;
    outputFile << "C++ file handling is fun!" << endl;

    // Close the output file
    outputFile.close();

    // Step 2: Open the file again as an input file
    ifstream inputFile("example.txt");
    if (!inputFile) {
        cerr << "Error opening input file." << endl;
        return 1;
    }

    // Reading the information from the file
    string line;
    cout << "Contents of the file:" << endl;
    while (getline(inputFile, line)) {
        cout << line << endl;
    }

    // Close the input file
    inputFile.close();

    return 0;
}


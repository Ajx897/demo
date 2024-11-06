#include <iostream>
#include <fstream> // For file handling
#include <string>
using namespace std;

int main()
{
    // File name
    const string filename = "example.txt";
    // Step 1: Create and write to the file
    {
        // Open file for writing (creates the file if it doesn't exist)
        ofstream outFile(filename);
        
        // Check if the file was opened successfully
        if (!outFile)
        {
            cerr << "Error opening file for writing.\n";
            return 1; // Return with error code
        }
        // Write some information to the file
        outFile << "Hello, World!\n";
        outFile << "This is a test file.\n";
        outFile << "File handling in C++ is easy.\n";
        // Close the file
        outFile.close();
    }
    // Step 2: Open the file again for reading and read its contents
    {
        // Open file for reading
        ifstream inFile(filename);
        // Check if the file was opened successfully
        if (!inFile)
        {
            cerr << "Error opening file for reading.\n";
            return 1; // Return with error code
        }
        // Read and display the contents of the file
        string line;
        cout << "File contents:\n";
        while (getline(inFile, line))
        {
            cout << line << '\n';
        }
        // Close the file
        inFile.close();
    }
    return 0; // Return with success code
}
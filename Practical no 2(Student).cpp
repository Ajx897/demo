#include <iostream>
#include <string>

using namespace std;

class Student {
private:
    string name; 
    int rollNumber;
    string className;
    char division;
    string dateOfBirth;
    string bloodGroup;
    string contactAddress;
    string telephoneNumber;
    string drivingLicenseNo;

public:			
    // Default Constructor
    Student() : rollNumber(0), division('A') {}

    // Parameterized Constructor
    Student(const string& name, int rollNumber, const string& className, char division,
            const string& dateOfBirth, const string& bloodGroup, 
            const string& contactAddress, const string& telephoneNumber,
            const string& drivingLicenseNo) 
        : name(name), rollNumber(rollNumber), className(className), 
          division(division), dateOfBirth(dateOfBirth), 
          bloodGroup(bloodGroup), contactAddress(contactAddress), 
          telephoneNumber(telephoneNumber), drivingLicenseNo(drivingLicenseNo) {}

    // Copy Constructor
    Student(const Student& other){
        name = other.name;
        rollNumber = other.rollNumber;
        className = other.className;
        division = other.division;
        dateOfBirth = other.dateOfBirth;
        bloodGroup = other.bloodGroup;
        contactAddress = other.contactAddress;
        telephoneNumber = other.telephoneNumber;
        drivingLicenseNo = other.drivingLicenseNo;
    }

    // Destructor
    ~Student() {}

    // Static member function to print the total number of students (dummy implementation)
    static void displayTotalStudents(int total) {
        cout << "Total Students: " << total << endl;
    }

    // Function to display student details
    void display() const {
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Class: " << className << endl;
        cout << "Division: " << division << endl;
        cout << "Date of Birth: " << dateOfBirth << endl;
        cout << "Blood Group: " << bloodGroup << endl;
        cout << "Contact Address: " << contactAddress << endl;
        cout << "Telephone Number: " << telephoneNumber << endl;
        cout << "Driving License No: " << drivingLicenseNo << endl;
    }

    // Friend function to modify student details
    friend void modifyStudent(Student& student, const string& newAddress) {
        student.contactAddress = newAddress;
    }

    // This pointer demonstration (inline function)
    void updateTelephoneNumber(const string& newNumber) {
        this->telephoneNumber = newNumber;  // using this pointer
    }
};

int main() {
    // Dynamic memory allocation for a Student object
    Student* student1 = new Student("John Doe", 101, "10th Grade", 'A', 
                                     "2005-06-15", "O+", 
                                     "123 Elm Street, City", 
                                     "1234567890", "DL123456");

    // Displaying student details
    student1->display();

    // Modifying student address using friend function
    modifyStudent(*student1, "456 Oak Street, City");

    // Updating telephone number
    student1->updateTelephoneNumber("0987654321");

    // Displaying updated student details
    student1->display();

    // Displaying total students (dummy value)
    Student::displayTotalStudents(1);

    // Deallocating memory
    delete student1;

    return 0;
}


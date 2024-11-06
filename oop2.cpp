// OOP Assignment_2

#include <iostream>
#include <cstring>
#include <exception>

using namespace std;

class Student
{
private:
    char *name;
    int rollNumber;
    char *studentClass;
    char division;
    char *dateOfBirth;
    char *bloodGroup;
    char *contactAddress;
    char *telephoneNumber;
    char *drivingLicenseNo;

    static int studentCount; // Static data member

public:
    // Constructor
    Student(const char *nm, int roll, const char *cls, char div, const char *dob, const char *bg,
            const char *addr, const char *phone, const char *licenseNo)
    {
        name = new char[strlen(nm) + 1];
        strcpy(name, nm);

        rollNumber = roll;

        studentClass = new char[strlen(cls) + 1];
        strcpy(studentClass, cls);

        division = div;

        dateOfBirth = new char[strlen(dob) + 1];
        strcpy(dateOfBirth, dob);

        bloodGroup = new char[strlen(bg) + 1];
        strcpy(bloodGroup, bg);

        contactAddress = new char[strlen(addr) + 1];
        strcpy(contactAddress, addr);

        telephoneNumber = new char[strlen(phone) + 1];
        strcpy(telephoneNumber, phone);

        drivingLicenseNo = new char[strlen(licenseNo) + 1];
        strcpy(drivingLicenseNo, licenseNo);

        studentCount++; // Increment the student count
    }

    // Default Constructor
    Student() : Student("Unknown", 0, "Unknown", 'X', "00-00-0000", "Unknown", "Unknown", "0000000000", "Unknown") {}

    // Copy Constructor
    Student(const Student &other)
    {
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);

        rollNumber = other.rollNumber;

        studentClass = new char[strlen(other.studentClass) + 1];
        strcpy(studentClass, other.studentClass);

        division = other.division;

        dateOfBirth = new char[strlen(other.dateOfBirth) + 1];
        strcpy(dateOfBirth, other.dateOfBirth);

        bloodGroup = new char[strlen(other.bloodGroup) + 1];
        strcpy(bloodGroup, other.bloodGroup);

        contactAddress = new char[strlen(other.contactAddress) + 1];
        strcpy(contactAddress, other.contactAddress);

        telephoneNumber = new char[strlen(other.telephoneNumber) + 1];
        strcpy(telephoneNumber, other.telephoneNumber);

        drivingLicenseNo = new char[strlen(other.drivingLicenseNo) + 1];
        strcpy(drivingLicenseNo, other.drivingLicenseNo);

        studentCount++; // Increment the student count
    }

    // Destructor
    ~Student()
    {
        delete[] name;
        delete[] studentClass;
        delete[] dateOfBirth;
        delete[] bloodGroup;
        delete[] contactAddress;
        delete[] telephoneNumber;
        delete[] drivingLicenseNo;
        studentCount--; // Decrement the student count
    }

    // Static Member Function
    static int getStudentCount()
    {
        return studentCount;
    }

    // Inline Function to Display Student Details
    inline void display() const
    {
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Class: " << studentClass << endl;
        cout << "Division: " << division << endl;
        cout << "Date of Birth: " << dateOfBirth << endl;
        cout << "Blood Group: " << bloodGroup << endl;
        cout << "Contact Address: " << contactAddress << endl;
        cout << "Telephone Number: " << telephoneNumber << endl;
        cout << "Driving License No: " << drivingLicenseNo << endl;
    }

    // Friend Class Declaration
    friend class Admin;

    // This Pointer Example
    void updatePhone(const char *newPhone)
    {
        strcpy(this->telephoneNumber, newPhone);
    }
};

// Initialize Static Data Member
int Student::studentCount = 0;

class Admin
{
public:
    void updateAddress(Student &student, const char *newAddress)
    {
        strcpy(student.contactAddress, newAddress);
    }
};

int main()
{
    try
    {
        // Dynamic Memory Allocation with Exception Handling
        Student *student1 = new Student("Vaibhav Sonar", 70, "SE-Computer ", 'D', "23-09-2005", "O+",
                                        "Vallabh Nagar, Pimpri, Pune.", "9876543210", "DL1234567");
        Student *student2 = new Student("Raj Patil", 00, "SE-Computer ", 'D', "02-02-2006", "B+",
                                        "Sant Tukaram Nagar, Pimpri, Pune", "0123456789", "DL0987654321");

        cout << "Student 1 Details:" << endl;
        student1->display();

        cout << "\nStudent 2 Details:" << endl;
        student2->display();

        cout << "\nTotal Students: " << Student::getStudentCount() << endl;

        // Using this pointer to update phone number
        student1->updatePhone("1112223334");
        cout << "\nUpdated Student 1 Phone Number:" << endl;
        student1->display();

        // Using Friend Class to update address
        Admin admin;
        admin.updateAddress(*student2, "Mukesh Nagar, Pimpri,Pune ");
        cout << "\nUpdated Student 2 Address:" << endl;
        student2->display();

        // Freeing dynamically allocated memory
        delete student1;
        delete student2;

        cout << "\nTotal Students after deletion: " << Student::getStudentCount() << endl;
    }
    catch (const bad_alloc &e)
    {
        cerr << "Memory allocation failed: " << e.what() << endl;
    }

    return 0;
}
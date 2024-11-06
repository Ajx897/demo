#include <iostream>
#include <string>
#include <stdexcept>
class Publication
{
protected:
    std::string title;
    float price;

public:
    // Default constructor
    Publication() : title(""), price(0.0f) {}
    // Parameterized constructor
    Publication(const std::string &t, float p) : title(t), price(p) {}
    // Input function
    virtual void input()
    {
        std::cout << "Enter title: ";
        std::getline(std::cin, title);
        std::cout << "Enter price: ";
        std::cin >> price;
        std::cin.ignore(); // Clear newline from input buffer
    }
    // Output function
    virtual void display() const
    {
        std::cout << "Title: " << title << "\n"
                  << "Price: " << price << "\n";
    }
    // Virtual destructor
    virtual ~Publication() {}
};
class Book : public Publication
{
private:
    int pageCount;

public:
    // Default constructor
    Book() : Publication(), pageCount(0) {}
    // Parameterized constructor
    Book(const std::string &t, float p, int pc) : Publication(t, p), pageCount(pc) {}
    // Input function
    void input() override
    {
        Publication::input();
        std::cout << "Enter page count: ";
        std::cin >> pageCount;
        std::cin.ignore(); // Clear newline from input buffer
    }
    // Output function
    void display() const override
    {
        Publication::display();
        std::cout << "Page Count: " << pageCount << "\n";
    }
};
class Tape : public Publication
{
private:
    float playingTime;

public:
    // Default constructor
    Tape() : Publication(), playingTime(0.0f) {}
    // Parameterized constructor
    Tape(const std::string &t, float p, float pt) : Publication(t, p), playingTime(pt) {}
    // Input function
    void input() override
    {
        Publication::input();
        std::cout << "Enter playing time (in minutes): ";
        std::cin >> playingTime;
        std::cin.ignore(); // Clear newline from input buffer
    }
    // Output function
    void display() const override
    {
        Publication::display();
        std::cout << "Playing Time: " << playingTime << " minutes\n";
    }
};
int main()
{
    try
    {
        // Create Book and Tape objects
        Book myBook;
        Tape myTape;
        // Input for Book
        std::cout << "Enter details for Book:\n";
        myBook.input();
        // Input for Tape
        std::cout << "Enter details for Tape:\n";
        myTape.input();
        // Display data
        std::cout << "\nBook Details:\n";
        myBook.display();
        std::cout << "\nTape Details:\n";
        myTape.display();
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << "\n";
        std::cerr << "Resetting all data to zero values.\n";

        // Create zero-initialized instances
        Book myBook;
        Tape myTape;
        // Display zero-initialized data
        std::cout << "\nBook Details (after exception):\n";
        myBook.display();
        std::cout << "\nTape Details (after exception):\n";
        myTape.display();
    }
    return 0;
}
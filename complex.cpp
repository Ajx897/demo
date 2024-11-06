#include <iostream>
using namespace std;

class Complex
{
private:
    double real;
    double imag;

public:
    // Default constructor (0 + 0i)
    Complex()
    {
        real = 0;
        imag = 0;
    }

    // Parameterized constructor
    Complex(double r, double i)
    {
        real = r;
        imag = i;
    }

    // Overload operator+ to add two complex numbers
    Complex operator+(const Complex &other) const
    {
        return Complex(real + other.real, imag + other.imag);
    }

    // Overload operator* to multiply two complex numbers
    Complex operator*(const Complex &other) const
    {
        return Complex(
            real * other.real - imag * other.imag,
            real * other.imag + imag * other.real);
    }

    // Overload operator<< to print a complex number
    friend ostream &operator<<(ostream &os, const Complex &c)
    {
        if (c.imag >= 0)
        {
            os << c.real << "+" << c.imag << "i";
        }
        else
        {
            os << c.real << c.imag << "i";
        }
        return os;
    }

    // Overload operator>> to read a complex number
    friend istream &operator>>(istream &is, Complex &c)
    {
        char sign;
        is >> c.real >> sign >> c.imag;
        if (sign == '-')
        {
            c.imag = -c.imag;
        }
        is.ignore(2); // Ignore the 'i' character and any additional whitespace
        return is;
    }
};

int main()
{
    Complex a(3, 2);
    Complex b(1, 7);

    // Addition
    Complex c = a + b;
    cout << "a + b = " << c << endl;

    // Multiplication
    Complex d = a * b;
    cout << "a * b = " << d << endl;

    // Reading from input
    Complex e;
    cout << "Enter a complex number (format: real+imagi): ";
    cin >> e;
    cout << "You entered: " << e << endl;
    return 0;
}
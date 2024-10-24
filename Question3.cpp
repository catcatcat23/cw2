#include <sstream>
#include <cmath>
#include <string>
#include <iostream>
using namespace std;

class Complex
{
    // WRITE YOUR CODE HERE
private:
    double a; 
    double b; 

public:
    Complex();
    Complex(double a, double b);
    Complex(double a);
    double getA() const;
    double getB() const;
    Complex add(const Complex& secondComplex) const;
    Complex subtract(const Complex& secondComplex) const;
    Complex multiply(const Complex& secondComplex) const;
    Complex divide(const Complex& secondComplex) const;
    double abs() const;
    string toString() const;
    Complex& operator+=(Complex& secondComplex);
    Complex& operator-=(Complex& secondComplex);
    Complex& operator*=(Complex& secondComplex);
    Complex& operator/=(Complex& secondComplex);
    double& operator[](const int& index);
    Complex& operator++();
    Complex& operator--();
    Complex operator++(int dummy);
    Complex operator--(int dummy);
    Complex operator+();
    Complex operator-();
    friend ostream& operator<<(ostream& str, const Complex& complex);
    friend istream& operator>>(istream& str, Complex& complex);
};

Complex operator+(const Complex& c1, const Complex& c2)
{
    // WRITE YOUR CODE HERE
    return c1.add(c2);
}

Complex operator-(const Complex& c1, const Complex& c2)
{
    // WRITE YOUR CODE HERE
    return c1.subtract(c2);
}

Complex operator*(const Complex& c1, const Complex& c2)
{
    // WRITE YOUR CODE HERE
    return c1.multiply(c2);
}

Complex operator/(const Complex& c1, const Complex& c2)
{
    // WRITE YOUR CODE HERE
    return c1.divide(c2);
}

Complex::Complex()
{
    // WRITE YOUR CODE HERE
    this->a = 0;
    this->b = 0;
}

Complex::Complex(double a, double b)
{
    // WRITE YOUR CODE HERE
    this->a = a;
    this->b = b;
}

Complex::Complex(double a)
{
    // WRITE YOUR CODE HERE
    this->a = a;
    this->b = 0;
}

double Complex::getA() const
{
    // WRITE YOUR CODE HERE
    { return a; }
}

double Complex::getB() const
{
    // WRITE YOUR CODE HERE
    { return b; }
}

Complex Complex::add(const Complex& secondComplex) const
{
    // WRITE YOUR CODE HERE
    return Complex(a + secondComplex.a, b + secondComplex.b);
}

Complex Complex::subtract(const Complex& secondComplex) const
{
    // WRITE YOUR CODE HERE
    return Complex(a - secondComplex.a, b - secondComplex.b);
}

Complex Complex::multiply(const Complex& secondComplex) const
{
    // WRITE YOUR CODE HERE
    return Complex(a * secondComplex.a - b * secondComplex.b,
        a * secondComplex.b + b * secondComplex.a);
}

Complex Complex::divide(const Complex& secondComplex) const
{
    // WRITE YOUR CODE HERE
    double denominator = secondComplex.a * secondComplex.a + secondComplex.b * secondComplex.b;
    return Complex((a * secondComplex.a + b * secondComplex.b) / denominator,
        (b * secondComplex.a - a * secondComplex.b) / denominator);
}

double Complex::abs() const
{
    // WRITE YOUR CODE HERE
    return sqrt(a * a + b * b);
}

string Complex::toString() const
{
    // WRITE YOUR CODE HERE
    stringstream ss;
    ss << a << (b >= 0 ? " + " : "") << b << "i";
    return ss.str();
}

Complex& Complex::operator+=(Complex& secondComplex)
{
    // WRITE YOUR CODE HERE
    a += secondComplex.a;
    b += secondComplex.b;
    return *this;
}

Complex& Complex::operator-=(Complex& secondComplex)
{
    // WRITE YOUR CODE HERE
    a -= secondComplex.a;
    b -= secondComplex.b;
    return *this;
}

Complex& Complex::operator*=(Complex& secondComplex)
{
    // WRITE YOUR CODE HERE
    double real = a * secondComplex.a - b * secondComplex.b;
    double imag = a * secondComplex.b + b * secondComplex.a;
    a = real;
    b = imag;
    return *this;
}

Complex& Complex::operator/=(Complex& secondComplex)
{
    // WRITE YOUR CODE HERE
    double denominator = secondComplex.a * secondComplex.a + secondComplex.b * secondComplex.b;
    double real = (a * secondComplex.a + b * secondComplex.b) / denominator;
    double imag = (b * secondComplex.a - a * secondComplex.b) / denominator;
    a = real;
    b = imag;
    return *this;
}

double& Complex::operator[](const int& index)
{
    // WRITE YOUR CODE HERE
    if (index == 0) return a;
    return b; 
}

Complex& Complex::operator++() // Prefix ++
{
    // WRITE YOUR CODE HERE
    ++a; 
    return *this;
}

Complex& Complex::operator--() // Prefix --
{
    // WRITE YOUR CODE HERE
    --a; 
    return *this;
}

Complex Complex::operator++(int dummy) // Postfix ++
{
    // WRITE YOUR CODE HERE
    Complex temp = *this;
    ++(*this);
    return temp;
}

Complex Complex::operator--(int dummy) // Postfix --
{
    // WRITE YOUR CODE HERE
    Complex temp = *this;
    --(*this);
    return temp;
}

Complex Complex::operator+() // Unary +
{
    // WRITE YOUR CODE HERE
    return *this;
}

Complex Complex::operator-() // Unary -
{
    // WRITE YOUR CODE HERE
    return Complex(-a, -b);
}

ostream& operator<<(ostream& str, const Complex& complex)
{
    // WRITE YOUR CODE HERE
    str << complex.a << " + " << complex.b << "i";

    return str;
}

istream& operator>>(istream& str, Complex& complex)
{
    // WRITE YOUR CODE HERE
    char ch;
    str >> complex.a >> complex.b >> ch;
    return str;
}

int main()
{
    Complex number1(3.5, 5.5);
    cout << "Enter the first complex number: " << number1 << endl;

    Complex number2(-3.5, 1);
    cout << "Enter the second complex number: " << number2 << endl;

    cout << "(" << number1 << ")" << " + " << "(" << number2
        << ") = " << (number1 + number2) << endl;
    cout << "(" << number1 << ")" << " - " << "(" << number2
        << ") = " << (number1 - number2) << endl;
    cout << "(" << number1 << ")" << " * " << "(" << number2
        << ") = " << (number1 * number2) << endl;
    cout << "(" << number1 << ")" << " / " << "(" << number2
        << ") = " << (number1 / number2) << endl;
    cout << "|" << number1 << "|" << " = " << number1.abs() << endl;

    number1[0] = 3.4;
    cout << "Overload the operator [], the new complex number is " << number1 << endl;
    number1++;
    cout << "Overload the operator postfix ++, the new complex number is " << number1 << endl;
    ++number2;
    cout << "Overload the operator prefix ++, the new complex number is " << number2 << endl;
    cout << "Overload the operator +, the result is " << (3 + number2) << endl;
    cout << "Overload the operator +=, the result is " << (number2 += number1) << endl;
    cout << "Overload the operator *=, the result is " << (number2 *= number1) << endl;

    return 0;
}

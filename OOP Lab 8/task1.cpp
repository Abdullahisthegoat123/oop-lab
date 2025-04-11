#include <iostream>
#include <cmath>
using namespace std;

class Complex
{
private:
    double real;
    double imag;

public:
    Complex(double r = 0.0, double i = 0.0)
    {
        real = r;
        imag = i;
    }

    Complex operator+(const Complex &other) const
    {
        return Complex(real + other.real, imag + other.imag);
    }

    Complex operator-(const Complex &other) const
    {
        return Complex(real - other.real, imag - other.imag);
    }

    Complex operator*(const Complex &other) const
    {
        double r = real * other.real - imag * other.imag;
        double i = real * other.imag + imag * other.real;
        return Complex(r, i);
    }

    Complex operator/(const Complex &other) const
    {
        double denom = other.real * other.real + other.imag * other.imag;
        double r = (real * other.real + imag * other.imag) / denom;
        double i = (imag * other.real - real * other.imag) / denom;
        return Complex(r, i);
    }

    friend double magnitude(const Complex &c);

    friend ostream &operator<<(ostream &out, const Complex &c);
};

double magnitude(const Complex &c)
{
    return sqrt(c.real * c.real + c.imag * c.imag);
}

ostream &operator<<(ostream &out, const Complex &c)
{
    out << "(" << c.real << (c.imag >= 0 ? " + " : " - ") << abs(c.imag) << "i)";
    return out;
}

int main()
{
    Complex a(3, 4);
    Complex b(1, -2);

    Complex sum = a + b;
    Complex diff = a - b;
    Complex prod = a * b;
    Complex quot = a / b;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "a + b = " << sum << endl;
    cout << "a - b = " << diff << endl;
    cout << "a * b = " << prod << endl;
    cout << "a / b = " << quot << endl;
    cout << "Magnitude of a: " << magnitude(a) << endl;
    cout << "Magnitude of b: " << magnitude(b) << endl;
}

#include <iostream>
#include <stdexcept>

using namespace std;

class InvalidTemperatureException : public exception
{
};

template <typename T>
T convertToFahrenheit(T celsius)
{
    if (celsius < -273.15)
    {
        throw InvalidTemperatureException();
    }
    return (celsius * 9 / 5) + 32;
}

int main()
{
    try
    {
        cout << "Attempting to convert -300C..." << endl;
        double fahrenheit = convertToFahrenheit(-300.0);
        cout << "Fahrenheit: " << fahrenheit << endl;
    }
    catch (const InvalidTemperatureException &e)
    {
        cout << "Caught InvalidTemperatureException - what(): " << e.what() << endl;
    }

    return 0;
}
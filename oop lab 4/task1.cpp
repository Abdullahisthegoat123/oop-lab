#include <iostream>
using namespace std;
class car
{
    string brand;
    string model;
    float rentalprice;
    int available;

public:
    car()
    {
        brand = "Unknown";
        model = "Generic";
        rentalprice = 0.0;
        available = 1;
    }
    void updatecar(string b, string m, float r, int a)
    {
        brand = b;
        model = m;
        rentalprice = r;
        available = a;
    }
    void checkavailability()
    {
        if (available == 1)
        {
            cout << "Car is available for rent" << endl;
        }
        else
        {
            cout << "Car is not available for rent" << endl;
        }
    }
    void rentcar()
    {
        if (available == 1)
        {
            cout << "Congratulations! Car is rented" << endl;
            available = 0;
        }
        else
        {
            cout << "Sorry! Car is not available for rent" << endl;
        }
    }
};
int main()
{
    car c;
    int ch = 0;
    int begin = 1;
    cout << "-------- Car Rental System --------\n1. Update Car details\n2. Check Availability\n3. Rent the car\n4. Exit" << endl;
    while (begin == 1)
    {
        cout << "Enter your choice: ";
        cin >> ch;
        string b;
        string m;
        float r;
        int a;
        switch (ch)
        {
        case 1:
            cout << "Enter Brand: ";
            cin >> b;
            cout << "Enter Model: ";
            cin >> m;
            cout << "Enter Rental Price: ";
            cin >> r;
            cout << "Enter Availability: ";
            cin >> a;
            c.updatecar(b, m, r, a);
            break;
        case 2:
            c.checkavailability();
            break;
        case 3:
            c.rentcar();
            break;
        case 4:
            begin = 0;
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    }
}
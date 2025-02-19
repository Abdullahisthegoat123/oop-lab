#include <iostream>
using namespace std;
class car
{
    string brand;
    string model;
    float rentalprice;
    bool available;

public:
    car()
    {
        brand = "Unknown";
        model = "Generic";
        rentalprice = 0.0;
        available = true;
    }
    car(string b, string m, float r, bool a)
    {
        brand = b;
        model = m;
        rentalprice = r;
        available = a;
    }
    void applydiscount(int days)
    {
        if (available == 1)
        {
            if (days > 10)
            {
                rentalprice = rentalprice * 0.90;
            }
            else if (days > 5)
            {
                rentalprice = rentalprice * 0.95;
            }
        }
        else
        {
            cout << "Car is not available for rent" << endl;
        }
    }

    void updatecar(string b, string m, float r, bool a)
    {
        brand = b;
        model = m;
        rentalprice = r;
        available = a;
    }
    void checkavailability()
    {
        if (available == true)
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
        if (available)
        {
            int days;
            cout << "How many days do you want to rent the car: ";
            cin >> days;
            applydiscount(days);
            cout << "Congratulations! Car is rented at $" << rentalprice << " per day" << endl;
            available = false;
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
        bool a;
        switch (ch)
        {
        case 1:
            cout << "Enter Brand: ";
            cin >> b;
            cout << "Enter Model: ";
            cin >> m;
            cout << "Enter Rental Price: ";
            cin >> r;
            int availabilityinput;
            cout << "Enter availability (1 for available, 0 for not available): ";
            cin >> availabilityinput;
            if (availabilityinput == 1)
            {
                a = true;
            }
            else
            {
                a = false;
            }
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
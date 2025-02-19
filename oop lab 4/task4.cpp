#include <iostream>
using namespace std;
class car
{
    string brand;
    string model;
    float rentalprice;
    bool available;
    float totalrevenue;

public:
    car()
    {
        brand = "Unknown";
        model = "Generic";
        rentalprice = 0.0;
        available = true;
        totalrevenue = 0.0;
    }
    car(string b, string m, float r, bool a)
    {
        brand = b;
        model = m;
        rentalprice = r;
        available = a;
        totalrevenue = 0.0;
    }
    car(const car &c)
    {
        brand = c.brand;
        model = c.model;
        rentalprice = c.rentalprice;
        available = c.available;
        totalrevenue = c.totalrevenue;
    }
    ~car()
    {
        cout << "Object is deleted" << endl;
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
    void updaterevenue(int days)
    {
        if (available == true)
        {
            float revenue = rentalprice * days;
            this->totalrevenue += revenue;
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
            updaterevenue(days);
            cout << "Congratulations! Car is rented at $" << rentalprice << " per day" << endl;
            available = false;
        }
        else
        {
            cout << "Sorry! Car is not available for rent" << endl;
        }
    }
    void display()
    {
        cout << "Brand: " << brand << endl;
        cout << "Model: " << model << endl;
        cout << "Rental Price: $" << rentalprice << endl;
        cout << "Available: " << available << endl;
        cout << "Total Revenue: $" << totalrevenue << endl;
    }
};
int main()
{
    cout << "\nCopy constructor test" << endl;
    car c1("toyota", "corolla", 100, true);
    car c2 = c1;
    cout << "Car 1 availability: ";
    c1.checkavailability();
    cout << "\nCar 2 availability: ";
    c2.checkavailability();
    c2.updatecar("honda", "civic", 200, false);
    cout << "\nCar 1 availability: ";
    c1.checkavailability();
    cout << "\nCar 2 availability after modification: ";
    c2.checkavailability();
    cout << "\n End of copy constructor test" << endl;

    c1.rentcar();
    cout << "After renting car 1" << endl;
    cout << "Car 1 details" << endl;
    c1.display();
    cout << "Car 2 details" << endl;
    c2.display();
}
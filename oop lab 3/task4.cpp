#include <iostream>
using namespace std;
class car
{
    string brand;
    string model;
    int fuelCapacity;
    int currentFuelLevel;

public:
    void setBrand(string b)
    {
        brand = b;
    }
    void setModel(string m)
    {
        model = m;
    }
    void setFuelCapacity(int f)
    {
        fuelCapacity = f;
    }
    void setCurrentFuelLevel(int c)
    {
        currentFuelLevel = c;
    }
    void drivecar(int fuelspent)
    {
        if (fuelspent > currentFuelLevel)
        {
            cout << "Fuel is not enough to drive the car" << endl;
        }
        else
        {
            currentFuelLevel = currentFuelLevel - fuelspent;
            cout << "Car is driven" << endl;
        }
    }
    void display()
    {
        cout << "Brand: " << brand << endl;
        cout << "Model: " << model << endl;
        cout << "Fuel Capacity: " << fuelCapacity << endl;
        cout << "Current Fuel Level: " << currentFuelLevel << endl;
    }
    void refuel(int fuel)
    {
        if (currentFuelLevel + fuel > fuelCapacity)
        {
            cout << "Fuel is more than the capacity" << endl;
        }
        else
        {
            currentFuelLevel += fuel;
            cout << "Car is refueled" << endl;
        }
    }
};
int main()
{
    car c1;
    c1.setBrand("Toyota");
    c1.setModel("Corolla");
    c1.setFuelCapacity(50);
    c1.setCurrentFuelLevel(20);
    int ch;
    int begin = 1;
    while (begin == 1)
    {
        cout << "\nFuel Management System\nEnter your choice:\n1.Drive Car\n2.Refuel Car\n3.Check Car's status\n4.Exit\n";
        cin >> ch;
        switch (ch)
        {
        case 1:
            int fuel;
            cout << "Enter the fuel to be spent: ";
            cin >> fuel;
            c1.drivecar(fuel);
            break;
        case 2:
            int refuel;
            cout << "Enter the fuel to be refueled: ";
            cin >> refuel;
            c1.refuel(refuel);
            break;
        case 3:
            c1.display();
            break;
        case 4:
            begin = 0;
            break;
        default:
            cout << "Invalid choice" << endl;
        }
    }
}
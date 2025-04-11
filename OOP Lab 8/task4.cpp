#include <iostream>
#include <string>
using namespace std;

class Car;

class InventoryManager
{
public:
    void updatePrice(Car &car, double newPrice);
    void displayCarDetails(const Car &car);
};

class Car
{
private:
    string model;
    double price;

public:
    Car(string modelName, double carPrice) : model(modelName), price(carPrice) {}

    friend class InventoryManager;

    friend void comparePrice(const Car &car1, const Car &car2);
};

void InventoryManager::updatePrice(Car &car, double newPrice)
{
    if (newPrice > 0)
    {
        car.price = newPrice;
        cout << "Price of " << car.model << " updated to " << car.price << endl;
    }
    else
    {
        cout << "Invalid price. Update failed." << endl;
    }
}

void InventoryManager::displayCarDetails(const Car &car)
{
    cout << "Car Model: " << car.model << endl;
    cout << "Car Price: " << car.price << endl;
}

void comparePrice(const Car &car1, const Car &car2)
{
    if (car1.price > car2.price)
    {
        cout << car1.model << " is more expensive than " << car2.model << endl;
    }
    else if (car1.price < car2.price)
    {
        cout << car2.model << " is more expensive than " << car1.model << endl;
    }
    else
    {
        cout << car1.model << " and " << car2.model << " are priced equally." << endl;
    }
}

int main()
{
    Car car1("Toyota Corolla", 25000.0);
    Car car2("Honda Civic", 27000.0);

    InventoryManager manager;

    cout << "Initial Car Details:" << endl;
    manager.displayCarDetails(car1);
    cout << "-----------------------------" << endl;
    manager.displayCarDetails(car2);
    cout << "-----------------------------" << endl;

    manager.updatePrice(car1, 26000.0);
    manager.updatePrice(car2, 26500.0);
    cout << "-----------------------------" << endl;

    comparePrice(car1, car2);
    cout<<endl;
    return 0;
}
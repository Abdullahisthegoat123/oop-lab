#include <iostream>
using namespace std;

class vehicle
{
protected:
    string brand;
    int speed;

public:
    vehicle(string b, int s) : brand(b), speed(s) {}
    void displayDetails()
    {
        cout << "\n---------Vehicle Details---------\n";
        cout << "Brand: " << brand << endl;
        cout << "Speed: " << speed << endl;
        cout << "\n----------------------------------\n";
    }
};

class car : protected vehicle
{
protected:
    int seats;

public:
    car(string b, int s, int seats) : vehicle(b, s), seats(seats) {}
    void displayDetails()
    {
        cout << "\n---------Car Details---------\n";
        cout << "Brand: " << brand << endl;
        cout << "Speed: " << speed << endl;
        cout << "Seats: " << seats << endl;
        cout << "\n---------------------------\n";
    }
};

class electricCar : protected car
{
protected:
    int batteryLife;

public:
    electricCar(string b, int s, int se, int ba) : car(b, s, se), batteryLife(ba) {}
    void displayDetails()
    {
        cout << "\n---------Electric Car Details---------\n";
        cout << "Brand: " << brand << endl;
        cout << "Speed: " << speed << endl;
        cout << "Seats: " << seats << endl;
        cout << "Battery life: " << batteryLife << endl;
        cout << "---------------------------------------\n";
    }
};

int main()
{
    electricCar Ferrari("Ferrari", 200, 5, 1000);
    Ferrari.displayDetails();
}
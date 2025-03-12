#include <iostream>
using namespace std;

class AlarmSystem
{
    string securityLevel;

public:
    AlarmSystem(string l) : securityLevel(l) {}
    void display()
    {
        cout << "Security Level: " << securityLevel << endl;
    }
};

class SmartHome
{
    string smarthomename;
    AlarmSystem alarm;

public:
    SmartHome(string name, string l) : smarthomename(name), alarm(l) {}
    void display()
    {
        cout << "\nSmart Home Details: " << endl;
        cout << "Home Name: " << smarthomename << endl;
        alarm.display();
    }
};

int main()
{
    SmartHome h("White house mansion", "High");
    h.display();
}
#include <iostream>
using namespace std;

class device
{
protected:
    int ID;
    bool status;

public:
    device(int id, bool status) : ID(id), status(status) {}

    void display()
    {
        cout << "------------------------\n";
        cout << "Device ID: " << ID << endl;
        cout << "Status: ";
        if (status)
        {
            cout << "On";
        }
        else
        {
            cout << "Off";
        }
        cout<<endl;
        cout<< "------------------------\n";
    }
};

class smartPhone : virtual public device
{
protected:
    float screenSize;

public:
    smartPhone(int id, bool s, float size) : device(id, s), screenSize(size) {}

    void display()
    {
        cout << "------------------------\n";
        cout << "Device ID: " << ID << endl;
        cout << "Status: ";
        if (status)
        {
            cout << "On";
        }
        else
        {
            cout << "Off";
        }
        cout<<endl;
        cout << "Screen Size: " << screenSize << " inches" << endl;
        cout << "------------------------\n";
    }
};

class smartWatch : virtual public device
{
protected:
    bool heartRateMonitor;

public:
    smartWatch(int id, bool s, bool h) : device(id, s), heartRateMonitor(h) {}

    void display()
    {
        cout << "------------------------\n";
        cout << "Device ID: " << ID << endl;
        cout << "Status: ";
        if (status)
        {
            cout << "On";
        }
        else
        {
            cout << "Off";
        }
        cout<<endl;
        cout << "Heart Rate Monitor: ";
        if (heartRateMonitor)
        {
            cout << "Yes";
        }
        else
        {
            cout << "No";
        }
        cout<<endl;
        cout << "------------------------\n";
    }
};

class smartWearable : public smartPhone, public smartWatch
{
protected:
    int stepCounter;

public:
    smartWearable(int id, bool s, float size, bool h, int steps)
        : device(id, s), smartPhone(id, s, size), smartWatch(id, s, h), stepCounter(steps) {}

    void display()
    {
        cout << "-----------SmartWearable Details-----------\n";
        cout << "Device ID: " << ID << endl;
        cout << "Status: ";
        if (status)
        {
            cout << "On";
        }
        else
        {
            cout << "Off";
        }
        cout<<endl;
        cout << "Screen Size: " << screenSize << " inches" << endl;
        cout << "Heart Rate Monitor: ";
        if (heartRateMonitor)
        {
            cout << "Yes";
        }
        else
        {
            cout << "No";
        }
        cout<<endl;
        cout << "Step Counter: " << stepCounter << endl;
        cout << "--------------------------------------------\n";
    }
};

int main()
{
    smartWearable sw(1, true, 8 , true, 5000);
    sw.display();
    return 0;
}
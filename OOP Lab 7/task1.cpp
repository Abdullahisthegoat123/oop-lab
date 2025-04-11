#include <iostream>
using namespace std;

class Device
{
protected:
    int deviceID;
    string deviceName;
    bool isOn;
    string deviceLocation;

public:
    Device(int id, string name, string location)
        : deviceID(id), deviceName(name), deviceLocation(location), isOn(false) {}

    virtual void activate() { isOn = true; }
    virtual void deactivate() { isOn = false; }
    virtual bool getDeviceStatus() const { return isOn; }

    virtual void displayInfo() const
    {
        cout<<"Device Information\n";
        cout << "-----------------------------\n";
        cout << "Device ID: " << deviceID << endl;
        cout << "Name: " << deviceName << endl;
        cout << "Status: " << (isOn ? "On" : "Off") << endl;
        cout << "Location: " << deviceLocation << endl;
    }
};

class Light : public Device
{
private:
    int brightnessLevel;
    string colorMode;

public:
    Light(int id, string name, string location, int brightness, string color)
        : Device(id, name, location), brightnessLevel(brightness), colorMode(color) {}

    void displayInfo() const override
    {
        Device::displayInfo();
        cout << "Brightness: " << brightnessLevel << endl;
        cout << "Color Mode: " << colorMode << endl;
        cout << "-----------------------------\n";
    }
};

class Thermostat : public Device
{
private:
    int currentTemp;
    int targetTemp;
    string mode;

public:
    Thermostat(int id, string name, string location, int curr, int target, string m)
        : Device(id, name, location), currentTemp(curr), targetTemp(target), mode(m) {}

    bool getDeviceStatus() const override
    {
        cout << "Current Temperature: " << currentTemp << "C" << endl;
        return isOn;
    }
};

class SecurityCamera : public Device
{
private:
    int resolution;
    bool recordingStatus;
    bool nightVisionEnabled;

public:
    SecurityCamera(int id, string name, string location, int res)
        : Device(id, name, location), resolution(res), recordingStatus(false), nightVisionEnabled(false) {}

    void activate() override
    {
        recordingStatus = true;
        isOn = true;
        nightVisionEnabled = true;
    }
};

class SmartPlug : public Device
{
private:
    int powerConsumption;
    string timerSetting;

public:
    SmartPlug(int id, string name, string location, int power, string timer)
        : Device(id, name, location), powerConsumption(power), timerSetting(timer) {}

    void deactivate() override
    {
        isOn = false;
        cout << "Power used: " << powerConsumption << "W\n";
        cout << "Timer setting: " << timerSetting << "\n";
    }
};

int main()
{
    Light l1(101, "Ceiling Light", "Living Room", 70, "Warm White");
    Thermostat t1(202, "ThermoX", "Bedroom", 23, 26, "Cooling");
    SecurityCamera cam1(303, "CamPro", "Entrance", 1080);
    SmartPlug sp1(404, "PlugOne", "Kitchen", 1500, "2 hours");

    l1.activate();
    l1.displayInfo();

    t1.activate();
    t1.getDeviceStatus();

    cam1.activate();

    sp1.deactivate();

    return 0;
}
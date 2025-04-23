#include <iostream>
#include <string>
#include <cstdlib> 

using namespace std;

class WeatherSensor {
protected:
    string sensorId;
    string location;

public:
    WeatherSensor(string sensorId, string location) : sensorId(sensorId), location(location) {}

    virtual void readData() = 0;
    virtual void displayReport() = 0;

    string getSensorId() const { return sensorId; }
    string getLocation() const { return location; }
};

class Thermometer : public WeatherSensor {
private:
    double temperature;
    double humidity;
    string unit;

public:
    Thermometer(string sensorId, string location, string unit = "Celsius")
        : WeatherSensor(sensorId, location), temperature(0), humidity(0), unit(unit) {}

    void readData() override {
        temperature = 20.0 + (rand() % 15) - 5; 
        humidity = 45.0 + (rand() % 40);

        cout << "Thermometer " << sensorId << " collecting data from " << location << "..." << endl;
        cout << "Temperature: " << temperature << " " << unit << endl;
        cout << "Humidity: " << humidity << "%" << endl;
    }

    void displayReport() override {
        cout << "THERMOMETER REPORT - " << location << " (ID: " << sensorId << ")" << endl;
        cout << "- Temperature: " << temperature << " " << unit << endl;
        cout << "- Humidity: " << humidity << "%" << endl;

        if (temperature > 26.0) {
            cout << "- Status: High temperature detected" << endl;
        } else if (temperature < 18.0) {
            cout << "- Status: Low temperature detected" << endl;
        } else {
            cout << "- Status: Temperature is within normal range" << endl;
        }
    }
};

class Barometer : public WeatherSensor {
private:
    double pressure;
    double altitude;
    string pressureUnit;

public:
    Barometer(string sensorId, string location, string pressureUnit = "hPa")
        : WeatherSensor(sensorId, location), pressure(0), altitude(0), pressureUnit(pressureUnit) {}

    void readData() override {
        pressure = 1010.0 + (rand() % 25) - 10; 
        altitude = 90 + (rand() % 60);

        cout << "Barometer " << sensorId << " collecting data from " << location << "..." << endl;
        cout << "Pressure: " << pressure << " " << pressureUnit << endl;
        cout << "Altitude: " << altitude << " meters" << endl;
    }

    void displayReport() override {
        cout << "BAROMETER REPORT - " << location << " (ID: " << sensorId << ")" << endl;
        cout << "- Pressure: " << pressure << " " << pressureUnit << endl;
        cout << "- Altitude: " << altitude << " meters" << endl;

        if (pressure > 1025) {
            cout << "- Forecast: High pressure - Clear skies likely" << endl;
        } else if (pressure < 1005) {
            cout << "- Forecast: Low pressure - Possible rain or storms" << endl;
        } else {
            cout << "- Forecast: Stable weather conditions" << endl;
        }
    }
};

int main() {
    WeatherSensor* sensors[4];

    sensors[0] = new Thermometer("THERM-Abdullah Karim", "Rooftop");
    sensors[1] = new Thermometer("THERM-Hassan", "Ground Level");
    sensors[2] = new Barometer("BARO-Arif", "Weather Station");
    sensors[3] = new Barometer("BARO-Asif", "Observatory");

    for (int i = 0; i < 4; i++) {
        cout << "\n===================================" << endl;
        sensors[i]->readData();
        cout << "\n";
        sensors[i]->displayReport();
    }

    for (int i = 0; i < 4; i++) {
        delete sensors[i];
    }
}
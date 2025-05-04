#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    ifstream inputFile("vehicle2.txt");
    if (!inputFile.is_open()) {
        cerr << "Error: Unable to open the file 'vehicle2.txt'" << endl;
        return -1;
    }

    string line;
    while (getline(inputFile, line)) {
        if (line.empty() || line[0] == '#') {
            continue;
        }

        istringstream lineStream(line);
        string vehicleType, extraDetails;

        getline(lineStream, vehicleType, ',');
        getline(lineStream, extraDetails);

        size_t colonPos = extraDetails.find(':');
        if (colonPos == string::npos) {
            cerr << "Error: Invalid format in line: " << line << endl;
            continue;
        }

        string valueStr = extraDetails.substr(colonPos + 1);
        if (vehicleType == "AutonomousCar") {
            float softwareVersion = stof(valueStr);
            cout << "Autonomous Car Software Version: " << softwareVersion << endl;
        } else if (vehicleType == "Electric Vehicle") {
            int batteryCapacity = stoi(valueStr);
            cout << "Electric Vehicle Battery Capacity: " << batteryCapacity << endl;
        }
    }

    inputFile.close();
    return 0;
}
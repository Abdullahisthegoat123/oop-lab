#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main()
{
    ifstream fileInput("vechicles.txt");
    if (!fileInput.is_open())
    {
        cerr << "Error: Unable to open file!" << endl;
        return 0;
    }

    string line;
    while (getline(fileInput, line))
    {
        if (line.empty() || line[0] == '#')
        {
            continue;
        }

        istringstream lineStream(line);
        string type, id, name, year, extraData, certification;

        getline(lineStream, type, ',');
        getline(lineStream, id, ',');
        getline(lineStream, name, ',');
        getline(lineStream, year, ',');
        getline(lineStream, extraData, ',');
        getline(lineStream, certification, ',');

        cout << "Type: " << type << ", ID: " << id << ", Name: " << name
             << ", Year: " << year << ", ExtraData: " << extraData
             << ", Certification: " << certification << endl;
    }

    fileInput.close();
    return 0;
}
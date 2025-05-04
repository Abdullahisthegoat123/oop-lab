#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

int main()
{
    ifstream file;
    string readFile;

    file.open("Vehicle.txt");

    string type, ID, name, Year;
    string extraData;
    string certification;

    if (file.is_open())
    {
        while (getline(file, readFile))
        {
            istringstream newFiles(readFile);
            getline(newFiles, type, ',');
            getline(newFiles, ID, ',');
            getline(newFiles, name, ',');
            getline(newFiles, Year, ',');
            getline(newFiles, extraData, ',');
            getline(newFiles, certification, ',');
            
            int intYear = stoi(Year);

            cout << "Type: " << type << endl;
            cout << "ID: " << ID << endl;
            cout << "Name: " << name << endl;
            cout << "Year(String): " << Year << endl;
            cout << "Year(integer): " << intYear << endl;
            cout << "Extra Data: " << extraData << endl;
            cout << "Certification: " << certification << endl;
            cout << "------------------------------------" << endl;
        }
        file.close();
    }
    else
    {
        cerr << "Unable to open the file" << endl;
        exit(1);
    }
}
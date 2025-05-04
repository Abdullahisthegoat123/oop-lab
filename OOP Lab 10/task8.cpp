#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main()
{
    fstream file1;
    file1.open("config.txt", ios::in | ios::out);

    if (!file1)
    {
        cerr << "Can not open the file" << endl;
        exit(1);
    }

    file1.seekp(5, ios::beg);
    file1.write("XXXXX", 5);
    file1.close();

    ifstream file2;
    file2.open("config.txt");

    if (!file2)
    {
        cerr << "Can not open the file" << endl;
        exit(1);
    }
    char ch;

    while (file2.get(ch))
    {
        cout << ch;
    }
    cout << endl;
    file2.close();

    file1.close();
}
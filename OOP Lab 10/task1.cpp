#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main()
{
    ifstream input("vehicles.txt");
    string str;
    if (!input)
    {
        return 1;
    }
    while (getline(input, str))
    {
        if (str.empty() || str[0] == '#')
        {
            continue;
        }
        cout << str << endl;
    }
    input.close();
    
    return 0;
}
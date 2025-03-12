#include <iostream>
using namespace std;
class apartment
{
    int id;
    string address;
    string *name;

public:
    apartment(int id, string address, string name)
    {
        this->id = id;
        this->address = address;
        this->name = new string(name);
    }
    apartment(const apartment &a)
    {
        this->id = a.id;
        this->address = a.address;
        this->name = a.name;
    }
    ~apartment()
    {
        delete name;
    }
    void display()
    {
        cout << "ID: " << id << endl;
        cout << "Address: " << address << endl;
        cout << "Name: " << *name << endl;
    }
};
int main()
{
    apartment a1(1, "scheme 33 gulzar e hijri", "Deez Nuts");
    apartment a2 = a1;
    a1.display();
    a2.display();
    return 0;
}
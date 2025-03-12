#include <iostream>
using namespace std;

class doctor
{
    string name;
    string specialization;
    string experience;

public:
    doctor(string name, string specialization, string experience) : name(name), specialization(specialization), experience(experience) {}
    void display()
    {
        cout << "Name: " << name << endl;
        cout << "Specialization: " << specialization << endl;
        cout << "Experience: " << experience << endl;
    }
};

class hospital
{
    string name;
    doctor **list;
    int numberOfDoctors = 0;
    string owner;

public:
    hospital(string n, string o, int num)
    {
        name = n;
        owner = o;
        numberOfDoctors = num;
        list = new doctor *[num];
    }
    ~hospital() { delete[] list; }
    void addDoctor(doctor *d, int index)
    {
        if (index < numberOfDoctors)
            list[index] = d;
    }
    void display()
    {
        cout << "\n\n--------HOSPITAL--------\n";
        cout << "Name: " << name << endl;
        cout << "Owner: " << owner << endl;
        cout << "Number of doctors: " << numberOfDoctors << endl;
        cout << "\n----DOCTORS----\n";
        for (int i = 0; i < numberOfDoctors; i++)
        {
            cout << "\nDoctor # " << i + 1 << endl;
            list[i]->display();
        }
    }
};

int main()
{
    hospital h("Dow Medical hospital", "Abdullah Karim", 3);
    doctor d1("Abdullah", "Eye specialist", "10 years");
    doctor d2("shamveel", "physiologist", "8 years");
    doctor d3("Usman", "Orthopedic", "5 years");

    h.addDoctor(&d1, 0);
    h.addDoctor(&d2, 1);
    h.addDoctor(&d3, 2);

    h.display();

    return 0;
}
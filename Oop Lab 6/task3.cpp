#include <iostream>
using namespace std;

class person
{
protected:
    string name;
    int age;

public:
    person(string n, int a) : name(n), age(a) {}
    void display()
    {
        cout << "\n--------Persons Details--------\n";
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "\n--------------------------------\n";
    }
};

class teacher : protected person
{
protected:
    string subject;

public:
    teacher(string n, int a, string subject) : person(n, a), subject(subject) {}
    void display()
    {
        cout << "\n--------Teacher's Details--------\n";
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Subject: " << subject << endl;
        cout << "\n--------------------------------\n";
    }
};

class researcher : protected teacher
{
protected:
    string researchArea;

public:
    researcher(string n, int a, string subject, string r) : teacher(n, a, subject), researchArea(r) {}
    void display()
    {
        cout << "\n--------Researcher Details--------\n";
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Subject: " << subject << endl;
        cout << "Research Area: " << researchArea << endl;
        cout << "\n--------------------------------\n";
    }
};

class professor : protected researcher
{
protected:
    int publications;

public:
    professor(string n, int a, string subject, string r, int p) : researcher(n, a, subject, r), publications(p) {}
    void display()
    {
        cout << "\n--------Professor Details--------\n";
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Subject: " << subject << endl;
        cout << "Research Area: " << researchArea << endl;
        cout << "Publications: " << publications << endl;
        cout << "\n--------------------------------\n";
    }
};

int main()
{
    professor Abdullah("Abdullah Karim", 18, "Computer Science", "Cyber Security", 5);
    Abdullah.display();
}
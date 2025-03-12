#include <iostream>
#include <string>
using namespace std;

class Employee;

class Project
{
private:
    string title;
    string deadline;
    Employee *employees[10];
    int employeeCount;

public:
    Project(string t, string d) : title(t), deadline(d), employeeCount(0) {}

    string getTitle() { return title; }

    void addEmployee(Employee *emp)
    {
        if (employeeCount < 10)
        {
            employees[employeeCount++] = emp;
        }
    }
    void displayDetails();
};

class Employee
{
private:
    string name;
    string designation;
    Project *projects[10];
    int projectCount;

public:
    Employee(string n, string d) : name(n), designation(d), projectCount(0) {}

    void assignProject(Project *proj)
    {
        if (projectCount < 10)
        {
            projects[projectCount++] = proj;
            proj->addEmployee(this);
        }
    }

    void displayProjects() const
    {
        cout << "Employee: " << name << " (" << designation << ") is working on:\n";
        for (int i = 0; i < projectCount; i++)
            cout << "- " << projects[i]->getTitle() << "\n";
    }

    string getName() { return name; }
};

void Project ::displayDetails()
{
    cout << "Project: " << title << " (Deadline: " << deadline << ")\nEmployees Assigned:\n";
    for (int i = 0; i < employeeCount; i++)
        cout << "- " << employees[i]->getName() << "\n";
}

int main()
{
    Employee emp1("Abdullah", "Developer");
    Employee emp2("shamveel", "Tester");
    Project proj1("Project A", "30-6-25");
    Project proj2("Project B", "15-12-25");

    emp1.assignProject(&proj1);
    emp1.assignProject(&proj2);
    emp2.assignProject(&proj1);

    proj1.displayDetails();
    proj2.displayDetails();
    emp1.displayProjects();
    emp2.displayProjects();

    return 0;
}

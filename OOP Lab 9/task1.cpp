#include <iostream>
#include <string>

using namespace std;

class Patient
{
protected:
    string name;
    string id;

public:
    Patient(string name, string id) : name(name), id(id) {}

    virtual void displayTreatment() = 0;
    virtual double calculateCost() = 0;

    string getName() const { return name; }
    string getId() const { return id; }
};

class InPatient : public Patient
{
private:
    int daysStay;
    bool surgeryRequired;

public:
    InPatient(string name, string id, int daysStay, bool surgeryRequired)
        : Patient(name, id), daysStay(daysStay), surgeryRequired(surgeryRequired) {}

    void displayTreatment() override
    {
        cout << "Treatment Details (InPatient):" << endl;
        cout << "Name: " << name << ", ID: " << id << endl;
        cout << "Stay Duration: " << daysStay << " days" << endl;
        cout << "Surgery Required: " << (surgeryRequired ? "Yes" : "No") << endl;
        cout << "Includes daily care and monitoring." << endl;
    }

    double calculateCost() override
    {
        double baseCost = 1250.0 * daysStay;
        if (surgeryRequired)
        {
            baseCost += 4800.0;
        }
        return baseCost;
    }
};

class OutPatient : public Patient
{
private:
    bool diagnostic;
    int treatmentSessions;

public:
    OutPatient(string name, string id, bool diagnostic, int treatmentSessions)
        : Patient(name, id), diagnostic(diagnostic), treatmentSessions(treatmentSessions) {}

    void displayTreatment() override
    {
        cout << "Treatment Details (OutPatient):" << endl;
        cout << "Name: " << name << ", ID: " << id << endl;
        cout << "Diagnostic Tests: " << (diagnostic ? "Included" : "Not Included") << endl;
        cout << "Number of Sessions: " << treatmentSessions << endl;
        cout << "Includes follow-up and medication." << endl;
    }

    double calculateCost() override
    {
        double baseCost = 220.0;
        if (diagnostic)
        {
            baseCost += 370.0;
        }
        baseCost += 160.0 * treatmentSessions;
        return baseCost;
    }
};

int main()
{
    Patient *patients[4];

    patients[0] = new InPatient("Abdullah Karim", "IP101", 7, true);
    patients[1] = new InPatient("Usman", "IP102", 4, false);
    patients[2] = new OutPatient("Shamveel", "OP201", true, 3);
    patients[3] = new OutPatient("Kabeer", "OP202", false, 5);

    for (int i = 0; i < 4; i++)
    {
        cout << "\n-----------------------------------" << endl;
        patients[i]->displayTreatment();
        cout << "Total Cost: $" << patients[i]->calculateCost() << endl;
    }

    for (int i = 0; i < 4; i++)
    {
        delete patients[i];
    }
}
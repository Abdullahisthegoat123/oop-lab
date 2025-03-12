#include <iostream>
using namespace std;

class account
{
protected:
    int accountNumber;
    float balance;

public:
    account(int a, float b) : accountNumber(a), balance(b) {}

    void display()
    {
        cout << "--------Account Details--------\n";
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
        cout << "--------------------------------\n";
    }
};

class savingsAccount : protected account
{
    float interestRate;

public:
    savingsAccount(int a, float b, float r) : account(a, b), interestRate(r) {}

    void display()
    {
        cout << "--------Savings Account Details--------\n";
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
        cout << "Interest Rate: " << interestRate << endl;
        cout << "----------------------------------------\n";
    }
};

class checkingAccount : protected account
{
    float overdraftLimit;

public:
    checkingAccount(int a, float b, float l) : account(a, b), overdraftLimit(l) {}

    void display()
    {
        cout << "--------Checking Account Details--------\n";
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
        cout << "Overdraft Limit: " << overdraftLimit << endl;
        cout << "----------------------------------------\n";
    }
};

int main()
{
    savingsAccount s(1, 4000, 0.5);
    checkingAccount c(2, 3000, 1000);
    s.display();
    c.display();
    return 0;
}
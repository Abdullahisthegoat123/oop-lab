#include <iostream>
using namespace std;

class Account
{
    string accountNumber;
    double balance;

public:
    Account(string accNum, double bal) : accountNumber(accNum), balance(bal) {}
    friend void transferFunds(Account &sender, Account &receiver, double amount);
    friend class Manager;
};

void transferFunds(Account &sender, Account &receiver, double amount)
{
    if (amount > 0 && amount <= sender.balance)
    {
        sender.balance -= amount;
        receiver.balance += amount;
        cout << "Transferred " << amount << " from account " << sender.accountNumber
             << " to account " << receiver.accountNumber << endl;
    }
    else
    {
        cout << "Transfer failed: Invalid amount or insufficient balance." << endl;
    }
}

class Manager
{
public:
    void showDetails(const Account &acc)
    {
        cout << "Account Number: " << acc.accountNumber << endl;
        cout << "Current Balance: " << acc.balance << endl;
    }

    void withdraw(Account &acc, double amount)
    {
        if (amount > 0 && amount <= acc.balance)
        {
            acc.balance -= amount;
            cout << "Withdrawal successful. New balance: " << acc.balance << endl;
        }
        else
        {
            cout << "Withdrawal failed: Invalid amount or insufficient balance." << endl;
        }
    }

    void deposit(Account &acc, double amount)
    {
        if (amount > 0)
        {
            acc.balance += amount;
            cout << "Deposit successful. New balance: " << acc.balance << endl;
        }
        else
        {
            cout << "Deposit failed: Invalid amount." << endl;
        }
    }
};

int main()
{
    Account account1("ACC-101", 54050.55);
    Account account2("ACC-102", 65700.35);

    Manager manager;

    cout << "Initial Account Details:" << endl;
    manager.showDetails(account1);
    cout << "-----------------------------" << endl;
    manager.showDetails(account2);
    cout << "-----------------------------" << endl;

    manager.withdraw(account1, 34200.4);
    manager.deposit(account1, 23400.4);
    manager.withdraw(account2, 20300.50);
    cout << "-----------------------------" << endl;

    transferFunds(account1, account2, 500.40);
    cout << "-----------------------------" << endl;

    cout << "Final Account Details:" << endl;
    manager.showDetails(account1);
    cout << "-----------------------------" << endl;
    manager.showDetails(account2);

}
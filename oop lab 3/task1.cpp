#include <iostream>
using namespace std;
class wallet
{
    string ownerName;
    float totalBalance;
    string transactionHistory;

public:
    void setName(string name)
    {
        ownerName = name;
    }
    void setBalance(float balance)
    {
        totalBalance = balance;
    }
    void setTransactionHistory(string history)
    {
        transactionHistory = history;
    }
    void addMoney(float amount)
    {
        totalBalance += amount;
        transactionHistory += "Added " + to_string(amount) + " to wallet\n";
    }
    void spendMoney(float amount)
    {
        if (totalBalance >= amount)
        {
            totalBalance -= amount;
            transactionHistory += "Spent " + to_string(amount) + " from wallet\n";
        }
        else
        {
            cout << "Insufficient balance\n";
        }
    }
    void showBalance()
    {
        cout << "Owner Name: " << ownerName << endl;
        cout << "Total Balance: " << totalBalance << endl;
        cout << "Transaction History: " << transactionHistory << endl;
    }
};
int main()
{
    wallet w1;
    w1.setName("Abdullah Karim");
    w1.setBalance(1000);
    w1.setTransactionHistory("Initial balance: 1000\n");
    int ch;
    int begin = 1;
    while (begin == 1)
    {
        cout << "1. Add Money\n2. Spend Money\n3. Show Balance\n4. Exit\n";
        cin >> ch;
        switch (ch)
        {
        case 1:
            float amount;
            cout << "Enter amount to add: ";
            cin >> amount;
            w1.addMoney(amount);
            break;
        case 2:
            cout << "Enter amount to spend: ";
            cin >> amount;
            w1.spendMoney(amount);
            break;
        case 3:
            w1.showBalance();
            break;
        case 4:
            begin = 0;
            break;
        default:
            cout << "Invalid choice\n";
        }
    }
}
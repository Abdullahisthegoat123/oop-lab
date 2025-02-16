#include <iostream>
using namespace std;
class fitnesstracker
{
    string userName;
    int dailystepgoal = 0;
    int stepstaken = 0;
    int caloriesburned = 0;

public:
    void setName(string name)
    {
        userName = name;
    }
    void setGoal(int goal)
    {
        dailystepgoal = goal;
    }
    void checkGoal()
    {
        if (stepstaken >= dailystepgoal)
        {
            cout << "You have achieved your daily step goal." << endl;
        }
        else
        {
            cout << "You have not achieved your daily step goal." << endl;
        }
    }
    void addSteps(int steps)
    {
        stepstaken += steps;
    }
    int calculateCalories()
    {
        caloriesburned = stepstaken * 3;
        return caloriesburned;
    }
    void display()
    {
        cout << "User Name: " << userName << endl;
        cout << "Daily Step Goal: " << dailystepgoal << endl;
        cout << "Steps Taken: " << stepstaken << endl;
        cout << "Calories Burned: " << caloriesburned << endl;
    }
};
int main()
{
    fitnesstracker a;
    a.setName("Abdullah Karim");
    int ch;
    int begin = 1;
    while (begin == 1)
    {
        cout << "\nFitness Tracker Menu\nEnter your Choice\n1.Set Daily Step Goal\n2.Add Steps\n3.Check Goal\n4.Calculate Calories\n5.Display\n6.Exit\n ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            int g;
            cout << "Enter Daily Step Goal: ";
            cin >> g;
            a.setGoal(g);
            break;
        case 2:
            int n;
            cout << "Enter Steps: ";
            cin >> n;
            a.addSteps(n);
            break;
        case 3:
            a.checkGoal();
            break;
        case 4:
            cout << "Calories Burned: " << a.calculateCalories() << endl;
            break;
        case 5:
            a.display();
            break;
        case 6:
            begin = 0;
            break;
        default:
            cout << "Invalid Choice" << endl;
        }
    }
}
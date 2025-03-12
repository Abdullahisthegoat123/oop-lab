#include <iostream>
using namespace std;

class student
{
    int id;
    int n;
    int* examscores;
    string name;

    public : 
    student(int idd, string na)
    {
        id = idd;
        name = na;
        
        cout << "\nenter the number of exam scores: ";
        cin >> n;
        examscores = new int[n];
        
        for (int i = 0; i < n; i++)
        {
            cout<<"enter score#"<<i+1<<" : ";
            cin >> examscores[i];
        }
    }
    student(const student &obj)
    {
        id = obj.id;
        name = obj.name;
        n=obj.n;
        examscores=new int [obj.n];
        for (int i = 0; i < obj.n; i++)
        {
            examscores[i] = obj.examscores[i];
        }
    }
    void display()
    {
        cout << "\n..............................\n";
        cout << "ID: " << id << "\n";
        cout << "Name: " << name << endl;
        cout << "...Scores...\n";
        for (int i = 0; i < n; i++)
        {
            cout << "Score # " << i + 1 << " : " << examscores[i] << endl;
        }
        cout << "..............................\n";
    }
    ~student() {
        delete [] examscores;
    }
};

int main()
{
    student abdullah(1, "abdullah");
    student abdullah2 = abdullah;
    abdullah.display();
    abdullah2.display();
}
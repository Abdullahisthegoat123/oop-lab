#include <iostream>
using namespace std;

class Library
{
private:
    string books[50];
    string borrowed[50];
    string available[50];
    int total = 0;
    int borrowedTotal = 0;
    int availableTotal = 0;

public:
    void addBook(string bookName)
    {
        if (total < 50)
        {
            books[total] = bookName;
            available[availableTotal] = bookName;
            total++;
            availableTotal++;
            cout << "Book added successfully!\n";
        }
        else
        {
            cout << "Library is full!\n";
        }
    }

    void lendBook(string bookName)
    {
        bool foundInLibrary = false, foundInAvailable = false;
        for (int i = 0; i < total; i++)
        {
            if (books[i] == bookName)
            {
                foundInLibrary = true;
                for (int j = 0; j < availableTotal; j++)
                {
                    if (available[j] == bookName)
                    {
                        available[j] = "";
                        borrowed[borrowedTotal] = bookName;
                        borrowedTotal++;
                        availableTotal--;
                        foundInAvailable = true;
                        break;
                    }
                }
                break;
            }
        }
        if (foundInLibrary && foundInAvailable)
        {
            cout << "Book borrowed successfully!\n";
        }
        else if (!foundInLibrary)
        {
            cout << "Book not found in library!\n";
        }
        else
        {
            cout << "Book is already borrowed!\n";
        }
    }

    void returnBook(string bookName)
    {
        available[availableTotal] = bookName;
        availableTotal++;
        borrowedTotal--;
        cout << "Book returned successfully!\n";
    }

    void showBooks()
    {
        cout << "\n--- Library Books ---\n";
        for (int i = 0; i < total; i++)
        {
            cout << i + 1 << ": " << books[i] << endl;
        }
        cout << endl;
    }
};

int main()
{
    Library l;
    int begin = 1, ch;
    string bookName;

    while (begin == 1)
    {
        cout << "Library Management System\n";
        cout << "1. Add Book\n2. Lend Book\n3. Return Book\n4. Show Books\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "Enter book name: ";
            cin >> bookName;
            l.addBook(bookName);
            break;
        case 2:
            cout << "Enter book name to borrow: ";
            cin >> bookName;
            l.lendBook(bookName);
            break;
        case 3:
            cout << "Enter book name to return: ";
            cin >> bookName;
            l.returnBook(bookName);
            break;
        case 4:
            l.showBooks();
            break;
        case 5:
            begin = 0;
            break;
        default:
            cout << "Invalid option\n";
            break;
        }
    }
}

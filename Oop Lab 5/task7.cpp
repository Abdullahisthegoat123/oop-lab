#include <iostream>
#include <algorithm>
using namespace std;

class Product
{
    int id;
    string name;
    int quantity;

public:
    Product(int id, string n, int q) : id(id), name(n), quantity(q) {}

    int getId()
    {
        return id;
    }
    string getName()
    {
        return name;
    }
    int getQuantity()
    {
        return quantity;
    }

    void display()
    {
        cout << "ID: " << id << ", Name: " << name << ", Quantity: " << quantity << endl;
    }
};

bool compareByName(Product *a, Product *b)
{
    return a->getName() < b->getName();
}

class Inventory
{
    string name;
    int numberOfProducts;
    int capacity;
    Product **list;

public:
    Inventory(int c, string n)
    {
        name = n;
        numberOfProducts = 0;
        capacity = c;
        list = new Product *[capacity];
    }

    void addProduct(Product *p)
    {
        if (numberOfProducts < capacity)
        {
            list[numberOfProducts++] = p;
        }
        else
        {
            cout << "Inventory is full" << endl;
        }
    }

    void sortProducts()
    {
        sort(list, list + numberOfProducts, compareByName);
    }

    void searchById(int id)
    {
        for (int i = 0; i < numberOfProducts; i++)
        {
            if (list[i]->getId() == id)
            {
                cout << "Product found:\n";
                list[i]->display();
                return;
            }
        }
        cout << "Product with ID " << id << " not found.\n";
    }

    void displayProducts()
    {
        cout << "Product List:\n";
        for (int i = 0; i < numberOfProducts; i++)
        {
            list[i]->display();
        }
    }

    ~Inventory()
    {
        delete[] list;
    }
};

int main()
{
    Inventory warehouse(3, "Warehouse");

    Product p1(1, "chcocolate", 5);
    Product p2(2, "Bed", 10);
    Product p3(3, "Keyboard", 7);

    warehouse.addProduct(&p1);
    warehouse.addProduct(&p2);
    warehouse.addProduct(&p3);

    cout << "Before Sorting:\n";
    warehouse.displayProducts();

    warehouse.sortProducts();

    cout << "\nAfter Sorting:\n";
    warehouse.displayProducts();

    int n;
    cout << "enter id to search for: ";
    cin >> n;
    cout << "\nSearching for product with ID:" << n << "\n";
    warehouse.searchById(n);

    return 0;
}
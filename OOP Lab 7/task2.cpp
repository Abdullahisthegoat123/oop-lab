#include <iostream>
using namespace std;

class Product
{
protected:
    int productID;
    string productName;
    double unitPrice;
    int stockQuantity;

public:
    Product(int id, string name, double price, int quantity)
        : productID(id), productName(name), unitPrice(price), stockQuantity(quantity) {}

    virtual double getDiscountedPrice() const
    {
        return unitPrice * 0.8; // 20% discount by default
    }

    virtual double totalCost(int quantity) const
    {
        return unitPrice * quantity;
    }

    virtual void showProductDetails() const
    {
        cout << "\n--------------------------\n";
        cout << "[Product Details]\n";
        cout << "Product ID   : " << productID << endl;
        cout << "Name         : " << productName << endl;
        cout << "Price        : " << unitPrice << endl;
        cout << "In Stock     : " << stockQuantity << endl;
    }

    Product operator+(const Product &other) const
    {
        return Product(productID, productName, unitPrice + other.unitPrice, stockQuantity);
    }

    friend ostream &operator<<(ostream &out, const Product &p)
    {
        out << "[Product Info]\n"
            << "ID: " << p.productID << "\n"
            << "Name: " << p.productName << "\n"
            << "Price: " << p.unitPrice << "\n"
            << "Available: " << p.stockQuantity << "\n";
        return out;
    }
};

class Electronics : public Product
{
private:
    int warrantyMonths;
    string brandName;

public:
    Electronics(int id, string name, double price, int stock, int warranty, string brand)
        : Product(id, name, price, stock), warrantyMonths(warranty), brandName(brand) {}

    void showProductDetails() const override
    {
        Product::showProductDetails();
        cout << "Brand        : " << brandName << endl;
        cout << "Warranty     : " << warrantyMonths << " months\n";
        cout << "--------------------------\n";
    }
};

class Clothing : public Product
{
private:
    string size;
    string color;
    string material;

public:
    Clothing(int id, string name, double price, int stock, string sz, string clr, string mat)
        : Product(id, name, price, stock), size(sz), color(clr), material(mat) {}

    double getDiscountedPrice() const override
    {
        return (material == "Thick") ? unitPrice * 0.7 : unitPrice * 0.85;
    }
};

class FoodItem : public Product
{
private:
    string expiration;
    int calories;

public:
    FoodItem(int id, string name, double price, int stock, string exp, int cal)
        : Product(id, name, price, stock), expiration(exp), calories(cal) {}

    double totalCost(int quantity) const override
    {
        if (quantity > 10)
        {
            return unitPrice * quantity * 0.8; // 20% bulk discount
        }
        return unitPrice * quantity;
    }
};

class Book : public Product
{
private:
    string author;
    string genre;

public:
    Book(int id, string name, double price, int stock, string auth, string gen)
        : Product(id, name, price, stock), author(auth), genre(gen) {}

    void showProductDetails() const override
    {
        Product::showProductDetails();
        cout << "Author       : " << author << endl;
        cout << "Genre        : " << genre << endl;
    }
};

int main()
{
    Electronics phone(201, "Samsung Galaxy S21", 80000, 10, 24, "Samsung");
    phone.showProductDetails();

    Clothing shirt(202, "Men's Shirt", 3500, 20, "Large", "White", "Linen");
    shirt.showProductDetails();
    cout << "Original Price: " << shirt.totalCost(1);
    cout << "\nDiscounted Price: " << shirt.getDiscountedPrice() << "\n";

    FoodItem soda(203, "Pepsi", 120, 100, "6 Months", 150);
    soda.showProductDetails();
    cout << "Price for 5: " << soda.totalCost(5);
    cout << "\nPrice for 12 (Bulk): " << soda.totalCost(12) << "\n";

    Book calculus(204, "Advanced Calculus", 1500, 15, "Abdullah Karim", "Mathematics");
    calculus.showProductDetails();

    return 0;
}
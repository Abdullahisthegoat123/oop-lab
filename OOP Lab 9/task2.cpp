#include <iostream>
#include <string>

using namespace std;

class MenuItem
{
protected:
    string dishName;
    double price;

public:
    MenuItem(string dishName, double price) : dishName(dishName), price(price) {}

    virtual void showDetails() = 0;
    virtual void prepare() = 0;

    string getDishName() const { return dishName; }
    double getPrice() const { return price; }
};

class Appetizer : public MenuItem
{
private:
    bool isSpicy;
    bool needsGarnish;

public:
    Appetizer(string dishName, double price, bool isSpicy, bool needsGarnish)
        : MenuItem(dishName, price), isSpicy(isSpicy), needsGarnish(needsGarnish) {}

    void showDetails() override
    {
        cout << "Dish Type: Appetizer" << endl;
        cout << "Name: " << dishName << " | Price: $" << price << endl;
        cout << "Spiciness: " << (isSpicy ? "Spicy" : "Mild") << endl;
        cout << "Garnish: " << (needsGarnish ? "Required" : "Not Required") << endl;
        cout << "Estimated Preparation Time: 10-15 minutes" << endl;
    }

    void prepare() override
    {
        cout << "Steps to Prepare Appetizer: " << dishName << endl;
        cout << "1. Gather all necessary ingredients." << endl;
        cout << "2. Mix and prepare according to the recipe." << endl;
        if (needsGarnish)
        {
            cout << "3. Add garnish for presentation." << endl;
        }
        if (isSpicy)
        {
            cout << "4. Add spices as per taste." << endl;
        }
        cout << "5. Serve the dish fresh." << endl;
    }
};

class MainCourse : public MenuItem
{
private:
    int cookTimeMinutes;
    string sideDish;

public:
    MainCourse(string dishName, double price, int cookTimeMinutes, string sideDish)
        : MenuItem(dishName, price), cookTimeMinutes(cookTimeMinutes), sideDish(sideDish) {}

    void showDetails() override
    {
        cout << "Dish Type: Main Course" << endl;
        cout << "Name: " << dishName << " | Price: $" << price << endl;
        cout << "Cooking Time: " << cookTimeMinutes << " minutes" << endl;
        cout << "Side Dish: " << sideDish << endl;
        cout << "Served as a full portion." << endl;
    }

    void prepare() override
    {
        cout << "Steps to Prepare Main Course: " << dishName << endl;
        cout << "1. Prepare all ingredients and seasonings." << endl;
        cout << "2. Heat the cooking surface to the required temperature." << endl;
        cout << "3. Cook the main ingredients for " << cookTimeMinutes << " minutes." << endl;
        cout << "4. Prepare the side dish: " << sideDish << endl;
        cout << "5. Plate the main course with the side dish." << endl;
        cout << "6. Add final touches and serve." << endl;
    }
};

int main()
{
    MenuItem *dishes[4];

    dishes[0] = new Appetizer("Abdullah Karim's Pakoras", 8.50, true, true);
    dishes[1] = new Appetizer("Yousef's Nachos", 7.25, false, false);
    dishes[2] = new MainCourse("Hassan's Steak", 20.99, 40, "Mashed Potatoes");
    dishes[3] = new MainCourse("Arif's Pasta", 18.75, 25, "Garlic Bread");

    for (int i = 0; i < 4; i++)
    {
        cout << "\n===================================" << endl;
        dishes[i]->showDetails();
        cout << "\n";
        dishes[i]->prepare();
    }

    for (int i = 0; i < 4; i++)
    {
        delete dishes[i];
    }
}
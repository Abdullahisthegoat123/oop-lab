#include <iostream>
using namespace std;

class Level
{
    string name;
    int difficulty;

public:
    Level(string n, int d) : name(n), difficulty(d) {}
    void display()
    {
        cout << "Level: " << name << endl;
        cout << "Difficulty: " << difficulty << endl;
    }
};

class VideoGame
{
    string title;
    int numberOfLevels;
    Level **levels;
    string genre;

public:
    VideoGame(string t, string g, int num) : title(t), genre(g), numberOfLevels(num)
    {
        levels = new Level *[num];
    }
    ~VideoGame() { delete[] levels; }
    void addLevel(Level *l, int index)
    {
        if (index < numberOfLevels)
            levels[index] = l;
    }
    void display()
    {
        cout << "\n\n--------VIDEO GAME--------\n";
        cout << "Title: " << title << endl;
        cout << "Genre: " << genre << endl;
        cout << "Number of Levels: " << numberOfLevels << endl;
        cout << "\n--------LEVELS--------\n";
        for (int i = 0; i < numberOfLevels; i++)
        {
            cout << "\nLevel # " << i + 1 << endl;
            levels[i]->display();
        }
    }
};

int main()
{
    VideoGame game("Fortnite", "Battle royale", 3);
    Level l1("Easy", 3);
    Level l2("Medium", 5);
    Level l3("Boss Level", 10);

    game.addLevel(&l1, 0);
    game.addLevel(&l2, 1);
    game.addLevel(&l3, 2);

    game.display();

    return 0;
}
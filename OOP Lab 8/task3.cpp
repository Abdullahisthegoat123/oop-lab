#include <iostream>
using namespace std;

class Vector2D
{
    int xCoord;
    int yCoord;

public:
    Vector2D() : xCoord(0), yCoord(0) {}
    Vector2D(int x, int y) : xCoord(x), yCoord(y) {}

    Vector2D operator+(const Vector2D &vec) const
    {
        return Vector2D(xCoord + vec.xCoord, yCoord + vec.yCoord);
    }

    Vector2D operator-(const Vector2D &vec) const
    {
        return Vector2D(xCoord - vec.xCoord, yCoord - vec.yCoord);
    }

    Vector2D operator*(int scalar) const
    {
        return Vector2D(xCoord * scalar, yCoord * scalar);
    }

    friend void calculateDotProduct(const Vector2D &vec1, const Vector2D &vec2);

    friend ostream &operator<<(ostream &out, const Vector2D &vec);
};

ostream &operator<<(ostream &out, const Vector2D &vec)
{
    out << "(" << vec.xCoord << ", " << vec.yCoord << ")";
    return out;
}

void calculateDotProduct(const Vector2D &vec1, const Vector2D &vec2)
{
    int dotProduct = (vec1.xCoord * vec2.xCoord) + (vec1.yCoord * vec2.yCoord);
    cout << "Dot Product: " << dotProduct << endl;
}

int main()
{
    Vector2D vector1(4, 5);
    Vector2D vector2(3, 3);

    Vector2D vectorSum = vector1 + vector2;
    Vector2D vectorDiff = vector1 - vector2;
    Vector2D vectorScaled = vector1 * 5;

    cout << "Vector 1: " << vector1 << endl;
    cout << "Vector 2: " << vector2 << endl;
    cout << "Vector 1 + Vector 2: " << vectorSum << endl;
    cout << "Vector 1 - Vector 2: " << vectorDiff << endl;
    cout << "Vector 1 * 5: " << vectorScaled << endl;

    calculateDotProduct(vector1, vector2);

    return 0;
}
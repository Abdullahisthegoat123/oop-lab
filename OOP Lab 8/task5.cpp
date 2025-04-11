#include <iostream>
using namespace std;

class Matrix2x2;

class MatrixHelper
{
public:
    void updateElement(Matrix2x2 &matrix, int row, int col, int value);
};

class Matrix2x2
{
private:
    int elements[2][2];

public:
    Matrix2x2(int a, int b, int c, int d)
    {
        elements[0][0] = a;
        elements[0][1] = b;
        elements[1][0] = c;
        elements[1][1] = d;
    }

    Matrix2x2 operator+(const Matrix2x2 &other) const
    {
        return Matrix2x2(
            elements[0][0] + other.elements[0][0],
            elements[0][1] + other.elements[0][1],
            elements[1][0] + other.elements[1][0],
            elements[1][1] + other.elements[1][1]);
    }

    Matrix2x2 operator-(const Matrix2x2 &other) const
    {
        return Matrix2x2(
            elements[0][0] - other.elements[0][0],
            elements[0][1] - other.elements[0][1],
            elements[1][0] - other.elements[1][0],
            elements[1][1] - other.elements[1][1]);
    }

    Matrix2x2 operator*(const Matrix2x2 &other) const
    {
        return Matrix2x2(
            elements[0][0]*other.elements[0][0] + elements[0][1]*other.elements[1][0],
            elements[0][0]*other.elements[0][1] + elements[0][1]*other.elements[1][1],
            elements[1][0]*other.elements[0][0] + elements[1][1]*other.elements[1][0],
            elements[1][0]*other.elements[0][1] + elements[1][1]*other.elements[1][1]);
    }

    friend int determinant(const Matrix2x2 &matrix);

    friend class MatrixHelper;

    friend ostream &operator<<(ostream &out, const Matrix2x2 &matrix);
};

int determinant(const Matrix2x2 &matrix)
{
    return (matrix.elements[0][0] * matrix.elements[1][1]) -
           (matrix.elements[0][1] * matrix.elements[1][0]);
}

ostream &operator<<(ostream &out, const Matrix2x2 &matrix)
{
    out << matrix.elements[0][0] << " " << matrix.elements[0][1] << endl;
    out << matrix.elements[1][0] << " " << matrix.elements[1][1] << endl;
    return out;
}

void MatrixHelper::updateElement(Matrix2x2 &matrix, int row, int col, int value)
{
    if (row >= 0 && row < 2 && col >= 0 && col < 2)
    {
        matrix.elements[row][col] = value;
        cout << "Updated element at (" << row << ", " << col << ") to " << value << endl;
    }
    else
    {
        cout << "Invalid row or column index!" << endl;
    }
}

int main()
{
    Matrix2x2 matrix1(1, 2, 3, 4);
    Matrix2x2 matrix2(5, 6, 7, 8);

    cout << "Matrix 1:" << endl
         << matrix1;
    cout << "Matrix 2:" << endl
         << matrix2;

    Matrix2x2 sum = matrix1 + matrix2;
    cout << "Matrix 1 + Matrix 2:" << endl
         << sum;

    Matrix2x2 diff = matrix1 - matrix2;
    cout << "Matrix 1 - Matrix 2:" << endl
         << diff;

    Matrix2x2 product = matrix1 * matrix2;
    cout << "Matrix 1 * Matrix 2:" << endl
         << product;

    cout << "Determinant of Matrix 1: " << determinant(matrix1) << endl;

    MatrixHelper helper;
    helper.updateElement(matrix1, 0, 1, 10);
    cout << "Matrix 1 after update:" << endl;
    cout<< matrix1;
}
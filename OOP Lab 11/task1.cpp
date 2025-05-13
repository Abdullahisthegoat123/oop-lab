#include <iostream>
#include <vector>
#include <stdexcept>
#include <sstream>

using namespace std;

class DimensionMismatchException : public exception
{
    string message;

public:
    DimensionMismatchException(int rowsA, int colsA, int rowsB, int colsB)
    {
        stringstream ss;
        ss << "DimensionMismatchException - Matrices must have same dimensions ("
           << rowsA << "x" << colsA << " vs " << rowsB << "x" << colsB << ")!";
        message = ss.str();
    }

    const char *what() const noexcept override
    {
        return message.c_str();
    }
};

template <typename T>
class Matrix
{
    vector<vector<T>> data;
    int rows, cols;

public:
    Matrix(int r, int c) : rows(r), cols(c), data(r, vector<T>(c, 0)) {}

    void setElement(int r, int c, T value)
    {
        data[r][c] = value;
    }

    T getElement(int r, int c) const
    {
        return data[r][c];
    }

    int getRows() const { return rows; }
    int getCols() const { return cols; }

    Matrix<T> operator+(const Matrix<T> &other) const
    {
        if (rows != other.rows || cols != other.cols)
        {
            throw DimensionMismatchException(rows, cols, other.rows, other.cols);
        }

        Matrix<T> result(rows, cols);
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                result.setElement(i, j, data[i][j] + other.getElement(i, j));
            }
        }
        return result;
    }

    void print() const
    {
        for (const auto &row : data)
        {
            for (const auto &elem : row)
            {
                cout << elem << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    try
    {
        Matrix<int> matrixA(2, 2);
        matrixA.setElement(0, 0, 1);
        matrixA.setElement(0, 1, 2);
        matrixA.setElement(1, 0, 3);
        matrixA.setElement(1, 1, 4);

        Matrix<int> matrixB(2, 2);
        matrixB.setElement(0, 0, 5);
        matrixB.setElement(0, 1, 6);
        matrixB.setElement(1, 0, 7);
        matrixB.setElement(1, 1, 8);

        cout << "Matrix A:" << endl;
        matrixA.print();

        cout << "Matrix B:" << endl;
        matrixB.print();

        Matrix<int> result = matrixA + matrixB;

        cout << "Resultant Matrix (A + B):" << endl;
        result.print();
    }
    catch (const DimensionMismatchException &e)
    {
        cerr << e.what() << endl;
    }

    return 0;
}
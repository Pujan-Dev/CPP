#include <iostream>

using namespace std;

class MATRIX
{
private:
    int row, col;
    int **mat; // for 2d matrix

public:
    MATRIX(int r, int c) : row(r), col(c)
    {
        mat = new int *[row];
        for (int i = 0; i < row; i++)
        {
            mat[i] = new int[col];
            for (int j = 0; j < col; j++)
            {
                mat[i][j] = 0;
            }
        }
    }

    ~MATRIX()
    {
        for (int i = 0; i < row; i++)
        {
            delete[] mat[i];
        }
        delete[] mat;
    }

    void input()
    {
        cout << "Enter the elements of the matrix (" << row << "x" << col << "):" << endl;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                cin >> mat[i][j];
            }
        }
    }

    MATRIX operator+(const MATRIX &m1)
    {
        if (row != m1.row || col != m1.col)
        {
            cerr << "Matrix dimensions must match for addition!" << endl;
            exit(1);
        }
        MATRIX m2(row, col);
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                m2.mat[i][j] = mat[i][j] + m1.mat[i][j];
            }
        }
        return m2;
    }

    void display() const
    {
        cout << "Resultant Matrix:" << endl;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    int rows = 3, cols = 3;
    MATRIX m(rows, cols);
    MATRIX m2(rows, cols);

    cout << "Enter the matrix A: ";
    m.input();

    cout << "Enter the matrix B: ";
    m2.input();

    MATRIX m3 = m + m2;

    m3.display();

    return 0;
}

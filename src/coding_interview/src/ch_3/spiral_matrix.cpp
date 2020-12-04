#include <iostream>

using namespace std;

void spiral_mat(int **mat, int row, int column)
{
    cout << "Original matrix: " << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    cout << "operations: " << endl;

    int direction = 0;

    int left = 0, right = column - 1, bottom = row - 1, top = 0;

    int spiralMatrix[row * column];

    int index = 0;
    while (true)
    {
        cout << "direction --> " << direction << endl;
        /* traverse from left to right */
        if (direction == 0)
        {
            for (int i = left; i < right + 1; i++)
            {
                spiralMatrix[index++] = mat[top][i];
            }

            ++top;
        }

        /* traverse from top to bottom */
        else if (direction == 1)
        {
            for (int i = top; i < bottom + 1; i++)
            {
                spiralMatrix[index++] = mat[i][right];
            }

            --right;
        }

        /* traverse from right to left */
        else if (direction == 2)
        {
            for (int i = right; i >= left; i--)
            {
                spiralMatrix[index++] = mat[bottom][i];
            }
            --bottom;
        }

        /* traverse from bottom to top */
        else
        {
            // cout << "left: " << left << endl;
            for (int i = bottom; i >= top; i--)
            {
                spiralMatrix[index++] = mat[i][left];
            }
            ++left;
        }

        if (left > right || top > bottom)
        {
            break;
        }

        direction = (direction + 1) % 4;
    }

    cout << "Spiral Array: ";
    for (int i = 0; i < (row * column); i++)
    {
        cout << spiralMatrix[i] << " ";
    }
    cout << endl;
}

int main()
{
    int **m = new int *[4] {
        new int[4]{1, 2, 3, 4},
            new int[4]{5, 6, 7, 8},
            new int[4]{9, 10, 11, 12},
            new int[4]{13, 14, 15, 16},
    };

    spiral_mat(m, 4, 4);
}
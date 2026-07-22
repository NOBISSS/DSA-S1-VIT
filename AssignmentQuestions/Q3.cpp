#include <iostream>
using namespace std;

const int MAX_SIZE = 3;

int main()
{
    int arr[MAX_SIZE][MAX_SIZE] =
    {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int rotation_cnt = 2;

    for (int col = 0; col < MAX_SIZE; col++)
    {
        for (int r = 0; r < rotation_cnt; r++)
        {
            int temp = arr[MAX_SIZE - 1][col];

            for (int row = MAX_SIZE - 1; row > 0; row--)
                arr[row][col] = arr[row - 1][col];

            arr[0][col] = temp;
        }
    }

    cout << "Matrix after "<<rotation_cnt<<" column-wise rotation:\n";

    for (int i = 0; i < MAX_SIZE; i++)
    {
        for (int j = 0; j < MAX_SIZE; j++)
            cout << arr[i][j] << " ";

        cout << endl;
    }

    return 0;
}
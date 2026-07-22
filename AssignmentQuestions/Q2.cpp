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
    rotation_cnt %= MAX_SIZE;

    for (int row = 0; row < MAX_SIZE; row++)
    {
        for (int r = 0; r < rotation_cnt; r++)
        {
            int temp = arr[row][MAX_SIZE - 1];

            for (int col = MAX_SIZE - 1; col > 0; col--)
                arr[row][col] = arr[row][col - 1];

            arr[row][0] = temp;
        }
    }

    cout << "Matrix after "<<rotation_cnt<<" row-wise right rotation:\n";

    for (int i = 0; i < MAX_SIZE; i++)
    {
        for (int j = 0; j < MAX_SIZE; j++)
            cout << arr[i][j] << " ";

        cout << endl;
    }

    return 0;
}
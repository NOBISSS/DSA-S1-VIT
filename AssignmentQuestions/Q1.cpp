#include <iostream>
using namespace std;

const int MAX_SIZE = 5;

int arr[MAX_SIZE];
int arr_filled_size = 0;

void display()
{
    if (arr_filled_size == 0)
    {
        cout << "No elements to display.\n";
        return;
    }

    cout << "Displaying Elements:\n";

    for (int i = 0; i < arr_filled_size; i++)
        cout << arr[i] << " ";

    cout << endl;
}

void insert()
{
    if (arr_filled_size == MAX_SIZE)
    {
        cout << "Array is full. Delete an element before inserting.\n";
        return;
    }

    int no;

    cout << "Enter Value: ";
    cin >> no;

    arr[arr_filled_size++] = no;

    display();
}

void deleteElem()
{
    if (arr_filled_size == 0)
    {
        cout << "Array is empty.\n";
        return;
    }

    int no;
    bool found = false;

    cout << "Enter Value to Delete: ";
    cin >> no;

    for (int i = 0; i < arr_filled_size; i++)
    {
        if (arr[i] == no)
        {
            found = true;

            for (int j = i; j < arr_filled_size - 1; j++)
                arr[j] = arr[j + 1];

            arr_filled_size--;
            break;
        }
    }

    if (!found)
        cout << "Element not found.\n";

    display();
}

int main()
{
    int choice;

    do
    {
        cout << "\n1. INSERT\n";
        cout << "2. DELETE\n";
        cout << "3. DISPLAY\n";
        cout << "4. EXIT\n";

        cout << "Enter Your Choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                insert();
                break;

            case 2:
                deleteElem();
                break;

            case 3:
                display();
                break;

            case 4:
                cout << "Exited Successfully.\n";
                break;

            default:
                cout << "Invalid Choice.\n";
        }

    } while (choice != 4);

    return 0;
}
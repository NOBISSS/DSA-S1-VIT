#include <iostream>
using namespace std;
#define STACK_SIZE 5
int e_stack[STACK_SIZE], o_stack[STACK_SIZE];
int e_top = -1, o_top = -1;

void push()
{
    int no;
    cout << "Enter Value: ";
    cin >> no;
    if (no % 2 == 0)
    {
        if (e_top < STACK_SIZE - 1)
            e_stack[++e_top] = no;
        else
            cout << "Even Stack Overflow\n";
    }
    else
    {
        if (o_top < STACK_SIZE - 1)
            o_stack[++o_top] = no;
        else
            cout << "Odd Stack Overflow\n";
    }
}

void pop()
{
    if (e_top != -1)
        cout << "Popped from Even Stack : " << e_stack[e_top--] << endl;
    else
        cout << "Even Stack Underflow\n";
    if (o_top != -1)
        cout << "Popped from Odd Stack : " << o_stack[o_top--] << endl;
    else
        cout << "Odd Stack Underflow\n";
}

void peek()
{
    if (e_top != -1)
        cout << "Even Stack Top : " << e_stack[e_top] << endl;
    else
        cout << "Even Stack Empty\n";
    if (o_top != -1)
        cout << "Odd Stack Top : " << o_stack[o_top] << endl;
    else
        cout << "Odd Stack Empty\n";
}

void display()
{
    int maxTop = max(e_top, o_top);
    if (maxTop == -1)
    {
        cout << "Both Stacks are Empty\n";
        return;
    }
    cout << "\n|EVEN STACK|\t|ODD STACK|\n";
    for (int i = 0; i <= maxTop; i++)
    {
        if (i <= e_top)
            cout << e_stack[i];
        else
            cout << " ";
        cout << "\t\t";
        if (i <= o_top)
            cout << o_stack[i];

        cout << endl;
    }
}

void menu()
{
    cout << "\n1. PUSH";
    cout << "\n2. POP";
    cout << "\n3. PEEK";
    cout << "\n4. DISPLAY";
    cout << "\n5. EXIT";
}

int main(){
    int choice;
    do
    {
        menu();
        cout << "\nEnter Choice: ";
        cin >> choice;
        switch (choice)
        {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                cout << "Program Terminated";
                break;
            default:
                cout << "Invalid Choice";
        }
    } while (choice != 5);
    return 0;
}
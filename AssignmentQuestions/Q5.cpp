#include <iostream>
#include <cctype>
using namespace std;

const int STACK_SIZE = 5;

char vowel_stack[STACK_SIZE], conso_stack[STACK_SIZE];
int vowel_top = -1, conso_top = -1;

void display()
{
    int maxTop = max(vowel_top, conso_top);
    cout << "|VOWEL STACK|                |CONSONANT STACK|" << endl;
    for (int i = 0; i <= maxTop; i++)
    {
        if (i <= vowel_top)
            cout << vowel_stack[i];
        else
            cout << " ";
        cout << "\t\t\t\t";
        if (i <= conso_top)
            cout << conso_stack[i];
        cout << endl;
    }
}

void insert(string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        char ch = toupper(str[i]);
        if (ch < 'A' || ch > 'Z')
            continue;
        if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
        {
            if (vowel_top < STACK_SIZE - 1)
                vowel_stack[++vowel_top] = str[i];
        }
        else
        {
            if (conso_top < STACK_SIZE - 1)
                conso_stack[++conso_top] = str[i];
        }
    }
    display();
}

int main(){
    string str;
    cout << "Enter String: ";
    cin >> str;
    insert(str);
    return 0;
}
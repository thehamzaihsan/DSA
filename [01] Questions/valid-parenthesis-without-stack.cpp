#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main()
{
    string str;
    int count = 0;
    cin >> str;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ')')
        {
            count--;
        }
        else if (str[i] == '(')
        {
            count++;
        }
        if (count < 0)
        {
            cout << " this string is unbalanced " << endl;
            return 0;
        }
    }
    if (count == 0)
    {
        cout << " string is balanced " << endl;
    }
    else
    {
        cout << "string is balanced " << endl;
    }
    return 0;
}
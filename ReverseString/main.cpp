#include <iostream>
using namespace std;
#include "stack.h"
int main(){
    string s;
    cout << "Enter a string: ";
    cin >> s;
    Stack stack;
    for (int i = 0; i < s.length(); i++)
    {
        stack.push(s[i]);
    }
    stack.display();
}
#include <iostream>
using namespace std;

#include "stackchar.h"

int main(){
    string s;
    cout << "Enter a string: ";
    cin >> s;
    Stackc stack;
    for (int i = 0; i < s.length(); i++)
    {
        stack.push(s[i]);
    }
    stack.display();
}
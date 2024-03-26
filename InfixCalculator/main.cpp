#include <iostream>
#include "stack.h"
using namespace std;

int main(){
    Stack s;
    string infix;
    cout << "Enter the infix expression: ";
    cin >> infix;
    for (int i = 0; i < infix.length(); i++)
    {
        if(infix[i] == '('){
            s.push('(');
        }
        else if(infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/'){
            if(prcd())
        }
       
    }
    
}
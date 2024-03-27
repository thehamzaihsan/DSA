#include <iostream>
#include "stack.h"
using namespace std;

//+*
bool operatorPrecedence(char op1, char op2)
{
    // is op1>op2
    if(op1 == '*' && op2 == '/'){
        return false;
    }
    if (op1 == '*' || op1 == '/')
    {
        return true;
    }
    else if (op2 == '+' || op2 == '-')
    {
        return true;
    }
    else
    {
        return false;
    }
}

float Evaluate(float a , float b , char oper){
    if(oper == '+'){
        return a+b;
    }
    if(oper == '-'){
        return a-b;
    }
    if(oper == '*'){
        return a*b;
    }
    if(oper == '/'){
        return a/b;
    }
    return 0;
}

int main()
{
    Stack s;
    string infix = "2*3+4";
    cout << "Enter the infix expression: ";
    cin >> infix;
    cout << "postfix: ";
    for (int i = 0; i < infix.length(); i++)
    {
        if (infix[i] == '(')
        {
            s.push('(');
        }
        else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/')
        {
            if (s.isEmpty())
            {
                s.push(infix[i]);
            }
            else if (operatorPrecedence(infix[i], s.top()))
            {
                s.push(infix[i]);
            }
            else
            {
                while (operatorPrecedence(s.top(), infix[i]) && s.top() != '$')
                {   
                    cout << s.pop();
                }
                s.push(infix[i]);
            }
        }
        else if (infix[i] == ')')
        {
            while (s.top() != '(')
            {
                cout << s.pop();
            }
            s.pop();
        }
        else
        {
            cout << infix[i] << " ";
        }
    }

    while (!s.isEmpty())
    {
        cout << s.pop();
    }

    cout << endl;
}
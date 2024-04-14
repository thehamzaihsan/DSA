#include <iostream>
#include "stackchar.h"
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
    string postfix = "";
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
                while (operatorPrecedence(s.top(), infix[i]))
                {   

                    postfix+= s.pop();
                }
                s.push(infix[i]);
            }
        }
        else if (infix[i] == ')')
        {
            while (s.top() != '(')
            {
                postfix+= s.pop();
            }

            s.pop();
        
        }
        else
        {
            postfix+= infix[i];
        }
    }

    while (!s.isEmpty())
    {
       postfix+=s.pop();
    }

    cout << postfix;
    cout << endl;
}
#include <iostream>
#include "Node.h"
#include "stackchar.h"
#include "stack.h"
using namespace std;


bool operatorPrecedence(char op1, char op2)
{
    int weightOp1, weightOp2;

    switch(op1) {
        case '+':
        case '-':
            weightOp1 = 1;
            break;
        case '*':
        case '/':
            weightOp1 = 2;
            break;
        default:
            weightOp1 = -1; // for invalid operators
    }

    switch(op2) {
    
        case '+':
        case '-':
            weightOp2 = 1;
            break;
        case '*':
        case '/':
            weightOp2 = 2;
            break;
        default:
            weightOp2 = -1; // for invalid operators
    }

    // if operators have equal precedence, return false
    if(weightOp1 == weightOp2) {
        return false;
    }

    return weightOp1 > weightOp2;
}

int evaluate(string str){
    Stack s;
    for (int i = 0; i < str.size(); i++)
    {
        if(str[i] >= '0' && str[i] <= '9'){
            int integer = str[i] - '0';
            s.push(integer);
        }
        else{
                int op1 = s.pop();
                int op2 = s.pop();
            if(str[i] == '+'){
                s.push(op1 + op2);
            }
              if(str[i] == '-'){
                s.push(op1 - op2);
            }
              if(str[i] == '*'){
                s.push(op1 * op2);
            }
              if(str[i] == '/'){
                s.push(op1 / op2);
            }
        }
    }
    
    int answer = s.pop();
    if(!s.isEmpty()){
        cout << "INVALID EXPRESSION";
        return -1;
    }
    else{
        return answer;
    }
}





int main()
{
    Stackc s;
    string infix;
    cout << "Enter the infix expression: ";
    getline(cin,infix);
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
            postfix += infix[i];
        }
    }

    while (!s.isEmpty())
    {
       postfix+=s.pop();
    }

    cout << postfix;
    cout << endl;
    cout << "Evaluate: ";
    cout << evaluate(postfix);
    cout << endl;
}
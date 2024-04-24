#include <iostream>
#include "stack.h"
using namespace std;

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

int main(){
    string str;
    cin >> str;
    cout << evaluate(str);
    
}
#include <iostream>
#include "stack.h"
using namespace std;

void insertBottom(Stack *S , int x){
    if(S->isEmpty()){
        S->push(x);
    }
    else{
        int a = S->pop();
        insertBottom(S, x);
        S->push(a);
    }
}

void Reverse(Stack *S){
    if(S->isEmpty()){
        return;
    }
    else{
       
        int x  = S->pop();
        Reverse(S);
        insertBottom(S , x);
    }
}

int main(){
    Stack S;
    S.push(10);
    S.push(20);
    S.push(30);
    S.push(40);
    S.display();
    Reverse(&S);
    S.display();
}


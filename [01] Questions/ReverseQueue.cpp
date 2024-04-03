#include <iostream>
#include "Queue.h"
using namespace std;

// void insertBottom(Queue *S , int x){
//     if(S->isEmpty()){
//         S->push(x);
//     }
//     else{
//         int a = S->pop();
//         insertBottom(S, x);
//         S->push(a);
//     }
// }

void Reverse(Queue *S){
    if(S->isEmpty()){
        return;
    }
    else{
       
       S->Traverse();
        // cout << x;
        Reverse(S);
        // S->Enqueue(x);
    }
}

int main(){
    Queue Q;
    Q.Enqueue(10);
    Q.Enqueue(20);
    Q.Enqueue(30);
    Q.Enqueue(40);
    Q.Dequeue();
    Q.Traverse();
    // Reverse(&Q);
    Q.Traverse();
    
}


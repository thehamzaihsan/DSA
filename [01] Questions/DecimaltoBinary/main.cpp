#include <iostream>
#include "stack.h"
using namespace std;

int main(){
    int n;
    cout << "Enter a number: ";
    cin >> n;
    Stack s;
    while(n>0){
        s.push(n%2);
        n = n/2;
    }
    cout << "Binary number: ";
    s.display();
}
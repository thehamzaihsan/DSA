#include <iostream>
using namespace std;

bool checkPrime(int x , int n){
    if(x == 0){
        return false;
    }
    if(n < 2){
        return true;
    }else{
        if(x % n == 0){
            return false;
        }  
        else{
            return checkPrime(x , n-1);
        } 
    }
}

int main(){
    cout << checkPrime(0, -1);
}
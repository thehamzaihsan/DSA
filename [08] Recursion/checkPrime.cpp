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

bool checkPrimeIterative(int x) {
    if (x <= 1) {
        return false;
    }
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}




int main() {
    int num = 17;
    cout << "Recursive: " << (checkPrime(num, num / 2) ? "Prime" : "Not Prime") << endl;
    cout << "Iterative: " << (checkPrimeIterative(num) ? "Prime" : "Not Prime") << endl;
    return 0;
}
#include <iostream>
using namespace std;

int powerDirect(int n , int power){
    if(power == 0){
        return 1;
    }
    else{
        return n*powerDirect(n , power -1);
    }
}


int powerIndirectHelper(int base, int exponent, int result);

int powerIndirect(int base, int exponent) {
    return powerIndirectHelper(base, exponent, 1);
}

int powerIndirectHelper(int base, int exponent, int result) {
    if (exponent == 0) {
        return result;
    } else {
        return powerIndirect(base, exponent - 1) * base;
    }
}

int main(){
     cout << "Direct recursion: " << powerDirect(2, 5) << endl;
    cout << "Indirect recursion: " << powerIndirect(2, 5) << endl;
}
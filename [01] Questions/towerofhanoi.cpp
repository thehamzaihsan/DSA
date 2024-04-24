
#include <iostream>
using namespace std;


void toh(int n , char a , char b , char c){
    if(n == 1){
        cout << "moved from " << a << " to " << c << endl;
        return;
    }
    toh(n-1 , a , c , b);
    toh(1 , a , b , c);
    toh(n-1 , b , a , c);
}

int main(){
    toh(3 ,'a' , 'b' , 'c');
}
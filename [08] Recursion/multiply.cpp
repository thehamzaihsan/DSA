#include <iostream>
using namespace std;
int Multiply(int a[], int size)
{
    if(size == 0){
        return 1;
    }else{
        // cout << a[size] * Multiply(a , size-1);
         return a[size] * Multiply(a , size-1);
    }
}
int main()
{
    int a[5] = {1, 2, 3, 4, 5};
    cout <<  Multiply(a, 4);
    cout << endl;
}
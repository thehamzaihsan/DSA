#include <iostream>
using namespace std;

class Recursive{
    public:
    void function(int n){
        if(n < 0)
        {
            return;
        }
        else{
            cout << n << " ";
            function(n-1);
        }
    }
};

int main(){
    Recursive R;
    cout << "Enter any number:";
    int n;
    cin >> n;
    R.function(n);
    cout << endl;
}
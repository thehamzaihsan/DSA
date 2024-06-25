#include <iostream>
using namespace std;


string reverse(string str){
    if(str.length() == 0){
        return "";
    }
    return reverse(str.substr(1)) + str[0];
}

int main(){
    string str = "Hello";
    cout << reverse(str) << endl;

}



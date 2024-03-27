#include <iostream>
using namespace std;

bool isPalindrome(string s , int start , int end){
    if(end == 0){
        return true;
    }
    else if(s[start] != s[end]){
        return false;
    }
    else{
        return isPalindrome(s , start + 1 , end - 1);
    }
}
int main(){
    string s = "hamza";
    cout << isPalindrome(s, 0 , s.length() - 1);
}
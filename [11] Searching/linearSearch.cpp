#include <iostream>
using namespace std;

bool linearSearch(int list[], int n, int key){
    for(int i = 0; i < n; i++){
        if(list[i] == key){
            return true;
        }
    }
    return false;
}

int main(){
    int list[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(list) / sizeof(list[0]);
    int key = 5;
    cout << "Enter the key to search: ";
    cin >> key;
    if(linearSearch(list, n, key)){
        cout << "Found" << endl;
    }
    else{
        cout << "Not Found" << endl;
    }
}
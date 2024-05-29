#include <iostream>
using namespace std;

bool binarySearch(int list[], int low, int high, int key)
{
    int mid = (high + low) / 2;
    if(mid == low || mid == high){
        return false;
    }
    if (list[mid] == key)
    {
        return true;
    }
    else if (list[mid] > key)
    {
        return binarySearch(list, low, mid - 1, key);
    }
    else if(list[mid] < key)
    {
        return binarySearch(list, mid + 1, high, key);
    }
    return false;
}

int main()
{
    int list[] = {1, 2, 4, 5, 6, 7, 8, 9};
    int n = sizeof(list) / sizeof(list[0]);
    int key = 4;
    cout << "Enter the key to search: ";
    cin >> key;
    if (binarySearch(list, 0, n, key))
    {
        cout << "Found" << endl;
    }
    else
    {
        cout << "Not Found" << endl;
    }
}
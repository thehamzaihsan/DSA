#include <iostream>
using namespace std;

void Reverse(int a[], int size)
{

    if (size == -1)
    {
        return;
    }
    else
    {
        
        cout << a[size];
        Reverse(a, size - 1);
    }
}

void Sequential(int a[], int size, int index)
{
    if (index == size)
    {
        return;
    }
    else
    {
        cout << a[index];
        Sequential(a, size, index + 1);
    }
}

int main()
{
    int array[] = {1, 2, 3, 4, 5};
    cout << "Sequential Order: ";
    Sequential(array, 5 , 0);
    cout << endl;

    cout << "Descending Order: ";
    Reverse(array, 5 - 1);
    cout << endl;
}
#include <iostream>
using namespace std;

int main()
{
    // int *integer = new int;
    // *integer = 5;
    // cout << *integer << endl;

    // delete integer;

    // double *doubly = new double;
    // *doubly = 5.5;
    // cout << *doubly << endl;

    // return 0;

    int *array = new int[5];
    for (int i = 0; i < 5; i++)
    {
        array[i] = i;
        cout << "[" << i << "] = :" << array[i] << endl;
    }

    delete array;
}
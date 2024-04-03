#include <iostream>
using namespace std;

int main()
{
    int array[10];

    for (int i = 0; i < 10; i++)
    {
        array[i] = i;
        cout << "array[" << i << "] = " << array[i] << endl;
    }

    int sum = 0;
    int *p = array;
    for (int i = 0; i < 10; i++)
    {
        sum += *(p + i);
    }

    cout << "Sum: " << sum << endl;
}

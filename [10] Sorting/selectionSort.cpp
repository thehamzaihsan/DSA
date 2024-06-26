#include <iostream>
using namespace std;

int *selectionSort(int list[], int n)
{
    for (int i = 0; i < n-1; i++)
    {
        int min = i;

        for (int j = i+1; j < n; j++)
        {
            if (list[j] < list[min])
            {
                min = j;
                
            }
        }

        int temp = list[i];
        list[i] = list[min];
        list[min] = temp;
        
    }

    return list;
}

int main()
{
    int list[] = {67, 33, 21, 84, 49, 50, 75};
    int n = sizeof(list) / sizeof(list[0]);

    int *sortedList = selectionSort(list, n);

    cout << "Sorted List: ";
    for (int i = 0; i < n; i++)
    {
        cout << sortedList[i] << " ";
    }
    cout << endl;
}
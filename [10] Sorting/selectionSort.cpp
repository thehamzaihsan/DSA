#include <iostream>
using namespace std;

int *selectionSort(int list[], int n)
{
    //for i->n
    for (int i = 0; i < n; i++)
    {
        //min = i
        int min = i;
        //for i->n
        for (int j = i; j < n; j++)
        {
            //if list[j] < list[min]
            if (list[j] < list[min])
            {
                //min = j
                min = j;
            }
        }
        //swap list[i] and list[min]
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
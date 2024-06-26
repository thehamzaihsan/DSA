#include <iostream>
using namespace std;

int *insertionSort(int list[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int temp = list[i];
        int j = i - 1;

        while (j >= 0 && list[j] > temp)
        {
            list[j + 1] = list[j];
            j--;
        }
        list[j + 1] = temp;
    }

    return list;
}

int main()
{
    int list[] = {12, 8, 4, 6, 2, 0};
    int n = sizeof(list) / sizeof(list[0]);

    int *sortedList = insertionSort(list, n);
    for (int i = 0; i < n; i++)
    {
        cout << sortedList[i] << " ";
    }
}
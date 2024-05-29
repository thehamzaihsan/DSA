#include <iostream>
using namespace std;

int *bubbleSort(int list[], int n)
{

    bool swap;
    for (int i = 0; i < n; i++)
    {
        swap = false;

        for (int j = 0; j < n - i - 1; j++)
        {
            if (list[j] > list[j + 1])
            {
                swap = true;
                int temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }

        if (!swap)
        {
            break;
        }
    }
    return list;
}

int main()
{
    int list[] = {1, 2, 5, 3, 4};
    int n = sizeof(list) / sizeof(list[0]);

    int *sortedList = bubbleSort(list, n);
    for (int i = 0; i < n; i++)
    {
        cout << sortedList[i] << " ";
    }
}
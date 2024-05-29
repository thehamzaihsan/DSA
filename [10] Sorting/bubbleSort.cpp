#include <iostream>
using namespace std;

int *bubbleSort(int list[], int n)
{

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n - i - 1; j++)
        {
            if (list[j] > list[j + 1])
            {
                int temp = *(list + j);
                *(list + j) = *(list + j + 1);
                *(list + j + 1) = temp;
            }
        }
    }
    return list;
}

int main()
{
    int list[] = {7, 43, 21, 84, 49, 50, 75};
    int n = sizeof(list) / sizeof(list[0]);

    int *sortedList = bubbleSort(list, n);
    for (int i = 0; i < n; i++)
    {
        cout << sortedList[i] << " ";
    }
}
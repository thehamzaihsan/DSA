#include <iostream>
using namespace std;

int *insertionSort(int list[], int n)
{
    //for i->n
    for (int i = 1; i < n; i++)
    {
      
        //for i-1<-0
        for (int  j = i-1; j >= 0; j--)
        {
            //if list[j] > list[i]
            if(list[j] > list[i]){
                //swap list[j] and list[i]
                int temp = list[j];
                list[j] = list[i];
                list[i] = temp;

                i--;
            }
            else{
                break;
            }
        }
        
    }
    
   
    return list;
}

int main()
{
    int list[] = {12,8,4,6,2,0};
    int n = sizeof(list) / sizeof(list[0]);

    int *sortedList = insertionSort(list, n);
    for (int i = 0; i < n; i++)
    {
        cout << sortedList[i] << " ";
    }
}
#include <iostream>
using namespace std;
#define MAX_SIZE 5

struct Stack
{
    int *my_array = new int;
    int array_top = -1;
};
void push(Stack *S, int value)
{
    if (S->array_top >= MAX_SIZE)
    {
        cout << "array is full";
    }
    else
    {
        S->array_top++;
        S->my_array[S->array_top] = value;
    }
}
void pop(Stack *S)
{
    if (S->array_top < 0)
    {
        cout << "Stack Underflow...";
    }
    else
    {
        S->my_array[S->array_top] = 0;
        S->array_top--;
    }
}
void display(Stack *S)
{
    for (int i = 0; i < S->array_top + 1; i++)
    {
        cout << S->my_array[i] << " ";
    }
    cout << endl;
}

int sum(Stack *S)
{
    int count = 0;
    for (int i = 0; i < S->array_top + 1; i++)
    {
        count += S->my_array[i];
    }
    return count;
}

int main()
{
    
    Stack *S = new Stack;
    int marks;
    for (int i = 0; i < 5; i++)
    {
        cout << "Enter marks for student " << i + 1 << ": ";
        cin >> marks;
        push(S, marks);
    }
    display(S);
    cout << "Sum of the marks: " << sum(S) << endl;
    delete S;
    return 0;
}
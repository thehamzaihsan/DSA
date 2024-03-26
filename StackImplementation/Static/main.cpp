#include <iostream>
using namespace std;

#define MAX_SIZE 5
int *thearray = new int;

class Stack
{
private:
    int arrayTop;

public:
    Stack();
    bool empty();
    int size();
    int *top();
    int push(int);
    int pop();
    int getsize()
    {
        return arrayTop + 1;
    }
    void print()
    {
        if (getsize() == 0)
        {
            cout << "Stack is empty";
        }
        else
        {
            for (int i = 0; i < arrayTop + 1; i++)
            {
                cout << thearray[i] << " ";
            }
            cout << endl;
        }
    }
    void Reverse()
    {
        int *temp = new int;
        for (int i = 0; i < arrayTop + 1; i++)
        {
            temp[i] = thearray[arrayTop - i];
        }
        thearray = temp;
    }
};

bool Stack::empty()
{

    if (arrayTop > -1)
    {
        return false;
    }
    else
    {
        return true;
    }
}

int Stack::size()
{
    return arrayTop;
}

Stack::Stack(/* args */)
{
    arrayTop = -1;
}

int Stack::push(int object)
{
    if (getsize() >= MAX_SIZE)
    {
        cout << "max size reached";
    }
    else
    {

        arrayTop++;
        thearray[arrayTop] = object;
    }
    return object;
}

int Stack::pop()
{
    if (arrayTop < 0)
    {
        cout << "stack is empty";
        return 9;
    }
    else
    {
        int x = thearray[arrayTop];
        arrayTop--;
        return x;
    }
}

int *Stack::top()
{
    return &thearray[arrayTop - 1];
}

int main()
{
    Stack S1;
    int choice, value;

    do
    {
        cout << "\n1. Push\n2. Pop\n3. Get Size\n4. Check Empty\n5. Print Stack\n 6. Reverse Stack\n7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter a value to push: ";
            cin >> value;
            S1.push(value);
            break;
        case 2:

            value = S1.pop();
            cout << "Popped value: " << value << "\n";

            break;
        case 3:
            cout << "Size of stack: " << S1.getsize() << "\n";
            break;
        case 4:
            if (S1.empty())
            {
                cout << "Stack is empty.\n";
            }
            else
            {
                cout << "Stack is not empty.\n";
            }
            break;
        case 5:
            S1.print();
            break;
        case 6:
            S1.Reverse();
            break;
        case 7:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 7);

    return 0;
}
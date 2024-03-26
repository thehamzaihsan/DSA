#include <iostream>
using namespace std;
#define MAX_SIZE 10
class Queue
{
public:
    int rear;
    int front;
    int array[MAX_SIZE];
    Queue()
    {
        rear = -1;
        front = -1;
    }
    bool isFull()
    {
        if (rear == MAX_SIZE - 1)
        {
            cout << "full queue";
            return true;
        }
        return false;
    }
    bool isEmpty()
    {
        if (rear == front)
        {
            return true;
        }
        return false;
    }
    void enqueue(int x)
    {
        if (!isFull())
        {
            rear++;
            array[rear] = x;
        }
    }
    int dequeue()
    {
        if (!isEmpty())
        {
            return array[++front];
        }
        return 0;
    }
    void display()
    {
        for (int i = front + 1; i <= rear; i++)
        {
            cout << array[i] << " ";
        }
        cout << endl;
    }
    int Front()
    {
        if (!isEmpty())
        {
            return this->array[front];
        }
        return 0;
    }
};

int main()
{
    Queue q;
    //enque 10 item
    for (int i = 0; i < 10; i++)
    {
        q.enqueue(i);
    }
    q.display();
    q.dequeue();
    q.display();
    return 0;
}
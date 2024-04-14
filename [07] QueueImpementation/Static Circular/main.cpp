#include <iostream>
using namespace std;

#define SIZE 5
class CircQueue
{
public:
    int front = 0, rear = 0;
    int counter = 0;
    int items[SIZE];
    void enqueue(int data)
    {
        if (isFull())
        {
            cout << "Queue is full" << endl;
            return;
        }
        items[rear] = data;
        rear = (rear + 1) % SIZE;
        counter++;
    }
    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }
        items[front] = 0;
        front = (front + 1) % SIZE;
        counter--;
    }
    void traverse()
    {
        int temp = front;
        do
        {
            cout << items[temp];
            temp = (temp + 1) % SIZE;
        }while (temp != rear);
    }
    bool isFull()
    {
        if (counter == SIZE)
        {
            return true;
        }
        return false;
    }
    bool isEmpty()
    {
        if (counter == 0)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    CircQueue Q;
    Q.enqueue(10);
    Q.enqueue(20);
    Q.enqueue(30);
    Q.enqueue(40);
    Q.enqueue(50);
    Q.traverse();
}
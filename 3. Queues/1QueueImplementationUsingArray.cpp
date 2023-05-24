#include<iostream>
#include<climits>

using namespace std;

class Queue
{
    int *arr;
    int front;
    int rear;
    int size;
    int capacity;

    public:
    Queue(int s)
    {
        arr = new int[s];
        size = 0;
        capacity = s;
        front = 0;
        rear = 0;
    }

    bool isEmpty()
    {
        return front == rear;
    }

    int getSize()
    {
        return size;
    }

    void enqueue(int element)
    {
        if(rear == capacity)
        {
            cout << "Queue is full!";
            return;
        }

        else
        {
            arr[rear] = element;
            rear++;
            size++;
        }
    }

    int dequeue()
    {
        if(front == rear)
        {
            return INT_MIN;
        }

        else
        {
            int ans = arr[front];
            front++;
            size--;

            if (front == rear)
            {
                front = 0;
                rear = 0;
            }

            return ans;
        }
    }

    int getFront()
    {
        if(isEmpty())
        {
            cout << "Queue is empty!";
        }

        else
        {
            return arr[front];
        }
    }
};

int main()
{
    Queue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);

    cout<<q.getFront()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;

    cout<<q.getSize()<<endl;

    cout<<q.isEmpty()<<endl;
}
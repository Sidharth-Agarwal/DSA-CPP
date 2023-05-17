#include<iostream>
#include<climits>

using namespace std;

class Queue
{
    int *data;
    int front;
    int rear;
    int size;
    int capacity;

    public:

    Queue(int s)
    {
        data = new int[s];
        front = -1;
        rear = 0;
        size = 0;
        capacity = s;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    int getSize()
    {
        return size;
    }

    int frontNode()
    {
        if(isEmpty())
        {
            cout << "Queue is empty" << endl;
            return INT_MIN;
        }

        return data[front];
    }

    void enqueue(int element)
    {
        if(size == capacity)
        {
            cout << "Queue is full" << endl;
            return;
        }

        data[rear] = element;
        size++;
        rear = (rear + 1) % capacity;
        
        if(front == -1)
        {
            front = 0;
        }
    }

    int dequeue()
    {
        if(isEmpty())
        {
            cout << "Queue is empty" << endl;
            return INT_MIN;
        }

        int ans = data[front];
        front = (front + 1) % capacity;
        size--;

        if(size == 0)
        {
            front = -1;
            rear = 0;
        }

        return ans;
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

    cout<<q.frontNode()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;

    cout<<q.getSize()<<endl;

    cout<<q.isEmpty()<<endl;
}
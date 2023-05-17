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
        size = 0;
        front = -1;
        rear = 0;
        data = new int[s];
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
            int *newData = new int[2*capacity];

            int j = 0;

            for (int i = front; i < capacity;i++)
            {
                newData[j] = data[i];
                j++;
            }

            for (int i = 0; i < front;i++)
            {
                newData[j] = data[i];
                j++;
            }

            delete[] data;
            data = newData;
            rear = capacity;
            front = 0;
            capacity *= 2;
        }

        data[rear] = element;
        rear = (rear + 1) % capacity;

        if (front == -1)
        {
            front = 0;
        }

        size++;
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
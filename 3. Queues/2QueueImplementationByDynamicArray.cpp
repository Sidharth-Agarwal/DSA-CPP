#include<iostream>
#include<climits>

using namespace std;

class Queue
{
    int *data;
    int firstIndex;
    int nextIndex;
    int size;
    int capacity;

    public:

    Queue(int s)
    {
        data = new int[s];
        firstIndex = -1;
        nextIndex = 0;
        size = 0;
        capacity = s;
    }

    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        return size == 0;
    }
    
    int front()
    {
        if(isEmpty())
        {
            cout << "Queue is empty" << endl;
            return INT_MIN;
        }

        return data[firstIndex];
    }

    void enqueue(int element)
    {
        if(size == capacity)
        {
            int *newData = new int[2 * capacity];

            int j = 0;

            for (int i = firstIndex; i < capacity;i++)
            {
                newData[j] = data[i];
                j++;
            }

            for (int i = 0; i < firstIndex;i++)
            {
                newData[j] = data[i];
                j++;
            }

            delete[] data;
            data = newData;
            firstIndex = 0;
            nextIndex = capacity;
            capacity *= 2;
        }

        data[nextIndex] = element;
        nextIndex = (nextIndex + 1) % capacity;
        
        if(firstIndex == -1)
        {
            firstIndex = 0;
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

        int ans = data[firstIndex];
        firstIndex = (firstIndex+1)%capacity;
        size--;

        if(size == 0)
        {
            firstIndex = -1;
            nextIndex = 0;
        }

        return ans;
    }
};
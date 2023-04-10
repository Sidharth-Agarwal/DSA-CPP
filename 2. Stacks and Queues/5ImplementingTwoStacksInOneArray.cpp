#include<iostream>
#include<climits>

using namespace std;

class twoStacks
{
    int *array;
    int top1;
    int top2;
    int size;

    public:

    twoStacks(int size)
    {
        this->size = size;
        top1 = -1;
        top2 = size;
        array = new int[size];
    }

    bool isEmpty1()
    {
        return top1 == -1;
    }

    bool isEmpty2()
    {
        return top2 == size;
    }

    int top1()
    {
        if(top1 == -1)
        {
            cout << "Stack 1 Empty" << endl;
            return INT_MIN;
        }

        return array[top1];
    }

    int top2()
    {
        if(top2 == size)
        {
            cout << "Stack 2 Empty" << endl;
            return INT_MIN;
        }

        return array[top2];
    }

    void push1(int element)
    {
        if(top2-top1 > 1)
        {
            top1++;
            array[top1] = element;
        }
        else
        {
            cout << "Overflowed";
        }
    }

    void push1(int element)
    {
        if(top2-top1 > 1)
        {
            top2--;
            array[top2] = element;
        }
        else
        {
            cout << "Overflowed";
        }
    }

    int pop1()
    {
        if(top1 >= 0)
        {
            int ans = array[top1];
            top1--;
            return ans;
        }
        else
        {
            cout << "Stack 1 Empty" << endl;
            return INT_MIN;
        }
    }

    int pop2()
    {
        if(top2 < size)
        {
            int ans = array[top2];
            top2++;
            return ans;
        }
        else
        {
            cout << "Stack 2 Empty" << endl;
            return INT_MIN;
        }
    }
};

int main()
{
    // Just simple two stack code
}
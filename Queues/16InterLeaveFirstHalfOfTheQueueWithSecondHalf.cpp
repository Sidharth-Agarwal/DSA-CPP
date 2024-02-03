#include<iostream>
#include<queue>
#include<stack>

using namespace std;

// Using Stack
// Works for even length queue only
void interleaveFirstAndSecondHalves(queue<int> &input)
{
    if(input.size()%2 != 0)
    {
        cout << "Enter even number of elements";
        return;
    }

    int half = input.size() / 2;

    stack<int> s;
    
    // Taking half elements from the queue
    // Pushing them into stack
    for (int i = 0; i < half;i++)
    {
        s.push(input.front());
        input.pop();
    }

    // Emptying the stack
    // Pushing elements into the queue
    while(!s.empty())
    {
        input.push(s.top());
        s.pop();
    }

    // Taking half elements from the front
    // Pushing them at the end
    for (int i = 0; i < half; i++)
    {
        input.push(input.front());
        input.pop();
    }

    // Pushing the half of the queue into the stack - again
    for (int i = 0; i < half;i++)
    {
        s.push(input.front());
        input.pop();
    }

    // Interleaving the queue and the stack
    // One element from each at a time
    while(!s.empty())
    {
        input.push(s.top());
        s.pop();
        input.push(input.front());
        input.pop();
    }
}

// Using queue
void interleaveFirstAndSecondHalves2(queue<int> &input)
{
    if(input.size()%2 != 0)
    {
        cout << "Enter even number of elements";
        return;
    }

    int half = input.size() / 2;

    queue<int> q;

    // Pushing half of the queue into new queue
    for (int i = 0; i < half;i++)
    {
        q.push(input.front());
        input.pop();
    }

    // Interleaving the combining both queues
    // Into the input queue
    while(!q.empty())
    {
        input.push(q.front());
        q.pop();
        input.push(input.front());
        input.pop();
    }
}

int main()
{
    queue<int> q;
    q.push(11);
    q.push(12);
    q.push(13);
    q.push(14);
    q.push(15);
    q.push(16);
    q.push(17);
    q.push(18);
    q.push(19);
    q.push(20);

    interleaveFirstAndSecondHalves(q);

    while(!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    
    interleaveFirstAndSecondHalves2(q);

    while(!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
}
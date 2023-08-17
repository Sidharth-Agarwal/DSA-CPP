#include<iostream>
#include<queue>
#include<stack>

using namespace std;

void reverseQueue(queue<int> &input)
{
    if(input.size()==0)
    {
        return;
    }

    int front = input.front();
    input.pop();

    reverseQueue(input);

    input.push(front);
}

int main()
{
    queue<int> input;

    input.push(10);
    input.push(20);
    input.push(30);
    input.push(40);
    input.push(50);

    reverseQueue(input);

    while(!input.empty())
    {
        cout << input.front() << " ";
        input.pop();
    }
}
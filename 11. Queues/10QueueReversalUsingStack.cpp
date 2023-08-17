#include<iostream>
#include<queue>
#include<stack>

using namespace std;

void reverseQueue(queue<int> &input)
{
    stack<int> help;

    while(!input.empty())
    {
        help.push(input.front());
        input.pop();
    }

    while(!help.empty())
    {
        int element = help.top();
        input.push(element);
        help.pop();
    }
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
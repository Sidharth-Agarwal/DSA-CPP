#include<iostream>
#include<queue>
#include<stack>

using namespace std;

void reverseFirstKElements(queue<int> &input, int k)
{
    stack<int> help;

    for (int i = 0; i < k;i++)
    {
        help.push(input.front());
        input.pop();
    }

    while(!help.empty())
    {
        input.push(help.top());
        help.pop();
    }

    int remaining = input.size() - k;

    while(remaining--)
    {
        input.push(input.front());
        input.pop();
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

    int k;
    cout << "Enter the value of k : ";
    cin >> k;

    reverseFirstKElements(input, k);

    while(!input.empty())
    {
        cout << input.front() << " ";
        input.pop();
    }
}
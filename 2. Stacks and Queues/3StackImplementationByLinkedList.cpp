#include<iostream>
#include<climits>

using namespace std;

class Node
{
    public:

    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class Stack
{
    Node *head;
    int count;

    public:

    Stack()
    {
        head = NULL;
        count = 0;
    }

    int size()
    {
        return count;
    }

    bool isEmpty()
    {
        return count == 0;
    }

    int top()
    {
        if(isEmpty())
        {
            cout << "Stack Empty" << endl;
            return INT_MIN;
        }
        return head->data;
    }

    void push(int element)
    {
        Node *newNode = new Node(element);
        newNode->next = head;
        head = newNode;
        count++;
    }

    int pop()
    {
        if(isEmpty())
        {
            cout << "Stack Empty" << endl;
            return INT_MIN;
        }

        int ans = head->data;
        Node *temp = head;
        head = head->next;
        delete temp;
        count--;
        return ans;
    }
};

int main()
{
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    cout<<s.top()<<endl;

    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;

    cout<<s.size()<<endl;

    cout<<s.isEmpty()<<endl;
}
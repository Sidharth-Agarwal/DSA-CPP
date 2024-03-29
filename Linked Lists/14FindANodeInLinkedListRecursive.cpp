#include<iostream>

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

Node* takeInput()
{
    int data;
    cin >> data;

    Node *head = NULL;
    Node *tail = NULL;

    while(data!=-1)
    {
        Node *newNode = new Node(data);

        if(head == NULL)
        {
            head = newNode;
            tail = newNode;
        }

        else
        {
            tail->next = newNode;
            tail = newNode;
        }

        cin >> data;
    }

    return head;
}

int findNode(Node* head, int find)
{
    if(head == NULL)
    {
        return -1;
    }

    if(head->data == find)
    {
        return 0;
    }

    int smallAns = findNode(head->next, find);

    if(smallAns == -1)
    {
        return -1;
    }

    return smallAns + 1;
}

int main()
{
    Node *head = takeInput();

    cout << "Enter the node to find : ";
    int data;
    cin >> data;

    cout << "The position of the entered node is : " << findNode(head, data);
}
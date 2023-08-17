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

Node* kReverse(Node* head, int k)
{
    if(head == NULL)
    {
        return head;
    }

    if(k == 0 || k == 1)
    {
        return head;
    }

    int count = 0;
    Node *curr = head;
    Node *prev = NULL;
    Node *fwd = NULL;

    while(curr != NULL && count < k)
    {
        fwd = curr->next;
        curr->next = prev;
        prev = curr;
        curr = fwd;
        count++;
    }

    if(fwd != NULL)
    {
        head->next = kReverse(fwd, k);
    }

    return prev;
}

void print(Node* head)
{
    while(head)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

int main()
{
    Node *head = takeInput();

    int k;
    cin >> k;

    head = kReverse(head, k);

    print(head);
}
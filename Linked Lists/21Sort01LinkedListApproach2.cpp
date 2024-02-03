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

Node* sort01(Node* head)
{
    if(head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *zeroHead = NULL;
    Node *zeroTail = NULL;
    Node *oneHead = NULL;
    Node *oneTail = NULL;

    Node *temp = head;

    while(temp!=NULL)
    {
        if(temp->data == 0)
        {
            if(zeroHead == NULL)
            {
                zeroHead = temp;
                zeroTail = temp;
            }

            else
            {
                zeroTail->next = temp;
                zeroTail = zeroTail->next;
            }
        }

        else if(temp->data == 1)
        {
            if(oneHead == NULL)
            {
                oneHead = temp;
                oneTail = temp;
            }

            else
            {
                oneTail->next = temp;
                oneTail = oneTail->next;
            }
        }
        temp = temp->next;
    }

    if(oneHead == NULL)
    {
        zeroTail->next = NULL;
        return zeroHead;
    }

    if(zeroHead == NULL)
    {
        oneTail->next = NULL;
        return oneHead;
    }

    if(zeroHead!=NULL && oneHead!=NULL)
    {
        zeroTail->next = oneHead;
        oneTail->next = NULL;
        return zeroHead;
    }
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

    head = sort01(head);
    print(head);
}
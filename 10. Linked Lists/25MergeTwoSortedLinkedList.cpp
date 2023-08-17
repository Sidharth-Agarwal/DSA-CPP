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

Node* merge(Node* head1, Node* head2)
{
    if(head1 == NULL)
    {
        return head2;
    }

    if(head2 == NULL)
    {
        return head1;
    }

    Node *newHead = NULL;
    Node *newTail = NULL;

    
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
    cout << "Enter the first linked list : ";
    Node *head1 = takeInput();

    cout << "Enter the second linked list : ";
    Node *head2 = takeInput();

    Node *head3 = merge(head1, head2);
}
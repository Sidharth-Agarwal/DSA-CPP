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

void printIthNode(Node* head, int i)
{
    int pos = 0;

    Node *temp = head;

    while(temp!=NULL && pos<i)
    {
        pos++;
        temp = temp->next;
    }

    if(temp!=NULL)
    {
        cout << temp->data;
    }
}

int main()
{
    Node *head = takeInput();

    int position;
    cout << "Enter the position to print : ";
    cin >> position;

    printIthNode(head, position);
}
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

    ~Node()
    {

    }
};

Node* takeInput()
{
    int data;
    cin>>data;

    Node* head = NULL;
    Node* tail = NULL;

    while(data!=-1)
    {
        Node* newNode = new Node(data);

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
        
        cin>>data;
    }

    return head;
}

void print(Node* head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
}

Node* deleteNode(Node* head, int i)
{
    if(head == NULL)
    {
        return head;
    }

    if(i == 0)
    {
        return head->next;
    }

    int count = 0;
    Node* temp = head;

    while(count<i-1 && temp!=NULL)
    {
        temp=temp->next;
        count++;
    }

    if(temp == NULL || temp->next == NULL)
    {
        cout<<"Index not available";
        return head;
    }

    temp->next = temp->next->next;
    return head;
}

int main()
{
    cout<<"Enter the linked list : ";
    Node* head = takeInput();

    int i;
    cout<<"Enter the position to delete : ";
    cin>>i;

    head = deleteNode(head,i);

    cout<<"The updated linked list is : ";
    print(head);
}
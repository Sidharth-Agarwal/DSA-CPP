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

void deleteNode(Node* &head, int i)
{
    if(head == NULL)
    {
        return;
    }

    if(i==0)
    {
        head = head->next;
    }

    Node* temp = head;
    int count = 0;

    while(temp!=NULL && count<i-1)
    {
        count++;
        temp=temp->next;
    }

    if(temp==NULL || temp->next==NULL)
    {
        cout<<"Index not available";
        return;
    }

    temp->next = temp->next->next;

    return;
}

int main()
{
    cout<<"Enter the linked list : ";
    Node* head = takeInput();

    int i;
    cout<<"Enter the position to delete : ";
    cin>>i;

    deleteNode(head,i);

    cout<<"The updated linked list is : ";
    print(head);
}
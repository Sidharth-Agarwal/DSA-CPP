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

Node* insertNode(Node* head, int i, int data)
{   
    // If the linked list is empty
    if(head == NULL)
    {
        Node* newNode = new Node(data);
        head = newNode;
        return head;
    }

    // Inserting at the front of the linked list
    if(i==0)
    {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
        return head;
    }

    int count = 0;
    Node* temp = head;
    Node* newNode = new Node(data);

    // Iterating till the desired position
    while(count<i-1 && temp!=NULL)
    {
        temp = temp->next;
        count++;
    }

    // Inserting the node at correct position
    if(temp!=NULL)
    {
        Node* sub = temp->next;
        temp->next = newNode;
        newNode->next = sub;
    }
    
    return head;
}

int main()
{
    cout<<"Enter the linked list : ";
    Node* head = takeInput();

    int data;
    cout<<"Enter the node to be inserted : ";
    cin>>data;

    int i;
    cout<<"Enter the position of the node : ";
    cin>>i;

    head = insertNode(head,i,data);

    cout<<"The updated linked list is : ";
    print(head);
}
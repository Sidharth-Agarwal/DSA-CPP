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

void print(Node* head)
{
    while(head)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

void insert(Node* &head,int i, int data)
{   
    // If linked list is empty
    if(head == NULL)
    {
        Node* newNode = new Node(data);
        head = newNode;
    }

    Node* newNode = new Node(data);

    // To insert a node at the start
    if(i==0)
    {
        newNode->next = head;
        head = newNode;
    }

    int count = 0;
    Node* temp = head;

    // To stop a node before
    while(count < i-1 && temp!=NULL)
    {
        temp = temp->next;
        count++;
    }

    // Inserting the node at the position
    if(temp!=0)
    {
        Node *sub = temp->next;
        temp->next = newNode;
        newNode->next = sub;
    }
}

int main()
{
    cout<<"Enter the linked list : ";
    Node *head = takeInput();

    int data;
    cout<<"Enter the node to be inserted : ";
    cin>>data;

    int i;
    cout<<"Enter the position of the data : ";
    cin>>i;

    insert(head,i,data);

    cout<<"Updated linked list is : ";
    print(head);
}
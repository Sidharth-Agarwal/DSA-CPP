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

Node* evenOdd(Node* head)
{
    Node *oddHead = NULL;
    Node *oddTail = NULL;
    Node *evenHead = NULL;
    Node *evenTail = NULL;

    Node *temp = head;

    while(temp)
    {
        if(temp->data % 2 != 0)
        {
            if(oddHead == NULL)
            {
                oddHead = temp;
                oddTail = temp;
            }

            else
            {
                oddTail->next = temp;
                oddTail = oddTail->next;
            }
        }

        else
        {
            if(evenHead == NULL)
            {
                evenHead = temp;
                evenTail = temp;
            }

            else
            {
                evenTail->next = temp;
                evenTail = evenTail->next;
            }
        }

        temp = temp->next;
    }

    if (oddHead == NULL) 
    { 
        return evenHead; 
    } 
    else 
    {
        oddTail->next = evenHead; 
    }
    
    if (evenHead != NULL) 
    { 
        evenTail->next = NULL;
    }
    
    return oddHead; 
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

    head = evenOdd(head);
    print(head);
}
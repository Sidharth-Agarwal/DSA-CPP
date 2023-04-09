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

    Node *temp = head;

    int zero = 0;
    int one = 0;

    while(temp)
    {
        if(temp->data == 0)
        {
            zero++;
        }

        else
        {
            one++;
        }

        temp = temp->next;
    }
    //Correct till here

    temp = head;

    while(head)
    {
        if(zero!=0)
        {
            head->data = 0;
            zero--;
        }

        else
        {
            head->data = 1;
            one--;
        }

        head = head->next;
    }

    head = temp;
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

int main()
{
    Node *head = takeInput();

    head = sort01(head);
    print(head);
}
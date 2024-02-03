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

Node* sort012(Node* head)
{
    int zero = 0;
    int one = 0;
    int two = 0;

    Node *temp = head;

    while(temp)
    {
        if(temp->data == 0)
        {
            zero++;
        }

        else if(temp->data == 1)
        {
            one++;
        }

        else
        {
            two++;
        }

        temp = temp->next;
    }

    temp = head;

    while(temp)
    {
        if(zero!=0)
        {
            temp->data = 0;
            temp = temp->next;
            zero--;
        }

        else if(one!=0)
        {
            temp->data = 1;
            temp = temp->next;
            one--;
        }

        else
        {
            temp->data = 2;
            temp = temp->next;
        }
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

int main()
{
    Node *head = takeInput();

    head = sort012(head);
    print(head);
}
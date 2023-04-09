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

// Approach 1
int length(Node* head)
{
    int count = 0;

    while(head)
    {
        head = head->next;
        count++;
    }

    return count;
}

Node* midNode1(Node* head)
{
    if(head == NULL || head->next == NULL)
    {
        return head;
    }

    int len = length(head);

    Node* temp = head;
    int mid = len / 2;
    int count = 0;

    Node *ans = head;

    while(count < mid)
    {
        temp = temp->next;
        count++;
    }

    ans = temp;
    return ans;
}

int main()
{
    Node *head = takeInput();

    Node *mid = midNode1(head);
    cout << "The middle of the given linked list is : " << mid->data;
}
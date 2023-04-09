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

// Approach 2
Node* midNode(Node* head)
{
    if(head == NULL || head->next == NULL)
    {
        return head;
    }

    if(head->next->next == NULL)
    {
        return head->next;
    }

    Node *slow = head;
    Node *fast = head->next;

    // while(fast!=NULL && fast->next!=NULL)
    // {
    //     fast = fast->next->next;
    //     slow = slow->next;
    // }

    while(fast!=NULL)
    {
        fast = fast->next;

        if(fast!=NULL)
        {
            fast = fast->next;
        }

        slow = slow->next;
    }

    return slow;
}

int main()
{
    Node *head = takeInput();

    Node *mid = midNode(head);
    cout << "The middle of the given linked list is : " << mid->data;
}
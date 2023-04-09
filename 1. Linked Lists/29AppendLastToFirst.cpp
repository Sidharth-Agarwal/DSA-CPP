#include<iostream>

using namespace std;

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

Node* appendLastNToFirst(Node* head, int n)
{
    if(n == 0 || head == NULL)
    {
        return head;
    }

    Node *slow = head;
    Node *fast = head;
    Node *initialHead = head;

    for (int i = 0; i < n; i++)
    {
        fast = fast->next;
    }

    while(fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }

    Node *temp = slow->next;
    slow->next = NULL;
    fast->next = initialHead;
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

    int n;
    cin >> n;

    head = appendLastNToFirst(head,n);

    print(head);
}
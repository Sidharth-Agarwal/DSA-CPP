#include<iostream>
#include<vector>

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

Node* reverse(Node* head)
{
    if(head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *prev = NULL;
    Node *fwd = NULL;
    Node *curr = head;

    while(curr!=NULL)
    {
        fwd = curr->next;
        curr->next = prev;
        prev = curr;
        curr = fwd;
    }

    return prev;
}

bool checkPalindrome(Node* head)
{
    Node *start = head;
    Node *end = reverse(head);

    while(start!=NULL && end!=NULL)
    {
        if(start->data != end->data)
        {
            return false;
        }

        start = start->next;
        end = end->next;
    }

    return true;
}

int main()
{
    Node *head = takeInput();

    if(checkPalindrome(head))
    {
        cout << "The given linked list is palindrome";
    }
    else
    {
        cout << "The given linked list is not palindrome";
    }
}
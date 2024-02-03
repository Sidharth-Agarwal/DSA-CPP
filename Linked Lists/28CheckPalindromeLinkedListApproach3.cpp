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

Node* mid(Node* head)
{
    if(head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *slow = head;
    Node *fast = head;

    while(fast!=NULL && fast->next!=NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
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
    if(head == NULL || head->next == NULL)
    {
        return head;
    }
    
    // Finding the mid node
    Node *midNode = mid(head);

    Node *secondHead = midNode->next;
    midNode->next = NULL;
    secondHead = reverse(secondHead);

    // Comparing the two sub-lists
    Node *firstSubList = head;
    Node *secondSubList = secondHead;

    bool ans = true;

    while(secondSubList!=NULL)
    {
        if(firstSubList->data != secondSubList->data)
        {
            ans = false;
            break;
        }

        firstSubList = firstSubList->next;
        secondSubList = secondSubList->next;
    }

    // Rejoin the two sub-lists
    firstSubList = head;
    secondSubList = reverse(secondHead);

    while(firstSubList->next!=NULL)
    {
        firstSubList = firstSubList->next;
    }

    firstSubList->next = secondSubList;

    return ans;
}

int main()
{
    Node *head = takeInput();

    if(checkPalindrome(head))
    {
        cout << "The given linked list is palindrome.";
    }
    else
    {
        cout << "The given linked list is not palindrome.";
    }
}
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

bool palindrome(vector<int> arr)
{
    int n = arr.size();
    int start = 0;
    int end = n - 1;

    while(start <= end)
    {
        if(arr[start] != arr[end])
        {
            return false;
        }
        start++;
        end--;
    }

    return true;
}

bool checkPalindrome(Node* head)
{
    vector<int> arr;

    Node *temp = head;

    while(temp)
    {
        arr.push_back(temp->data);
        temp = temp->next;
    }

    return palindrome(arr);
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
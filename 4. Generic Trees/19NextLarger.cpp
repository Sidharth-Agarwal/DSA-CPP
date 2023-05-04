#include<iostream>
#include<queue>
#include<vector>
#include"0TreeNode.h"

using namespace std;

TreeNode<int>* takeInput()
{
    int data;
    cout << "Enter the root data : ";
    cin >> data;

    TreeNode<int> *root = new TreeNode<int>(data);

    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);

    while(pendingNodes.size() != 0)
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();

        int num;
        cout << "Enter the number of the chilren of " << front->data << " : ";
        cin >> num;

        for (int i = 0; i < num; i++)
        {
            int childData;
            cout << "Enter the " << i << "th child of the " << front->data << " : ";
            cin >> childData;

            TreeNode<int> *child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }

    return root;
}

void printTree(TreeNode<int>* root)
{
    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);

    while(pendingNodes.size() != 0)
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();

        for (int i = 0; i < front->children.size();i++)
        {
            if(i<front->children.size()-1)
            {
                cout << front->children[i]->data << ",";
            }
            else
            {
                cout << front->children[i]->data;
            }

            pendingNodes.push(front->children[i]);
        }

        cout << endl;
    }
}

TreeNode<int> *getNextLarger(TreeNode<int> *root, int x)
{
    if(root == NULL)
    {
        return NULL;
    }

    bool flag = false;

    TreeNode<int> *nextLarger = NULL;

    if(root->data > x)
    {
        flag = true;
        nextLarger = root;
    }

    for (int i = 0; i < root->children.size(); i++)
    {
        TreeNode<int> *temp = getNextLarger(root->children[i], x);

        if(nextLarger == NULL)
        {
            nextLarger = temp;
        }

        else if(temp!=NULL && temp->data < nextLarger->data)
        {
            nextLarger = temp;
            flag = true;
        }
    }

    return nextLarger;
}

int main()
{
    TreeNode<int> *root = takeInput();

    int x;
    cout << "Enter the element to find the next larger : ";
    cin >> x;

    TreeNode<int> *element = getNextLarger(root, x);

    if(element != NULL)
    {
        cout << "The next larger element is : " << element->data;
    }
}
#include<iostream>
#include<bits/stdc++.h>
#include"0BinaryTreeNode.h"

using namespace std;

BinaryTreeNode<int>* takeInput()
{
    int rootData;
    cout << "Enter the root data : ";
    cin >> rootData;

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);

    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    
    while(pendingNodes.size()!=0)
    {
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();

        int left;
        cout << "Enter the left child of " << front->data << " : ";
        cin >> left;

        if(left!=-1)
        {
            BinaryTreeNode<int> *leftChild = new BinaryTreeNode<int>(left);
            pendingNodes.push(leftChild);
            front->left = leftChild;
        }

        int right;
        cout << "Enter the right child of " << front->data << " : ";
        cin >> right;

        if(right!=-1)
        {
            BinaryTreeNode<int> *rightChild = new BinaryTreeNode<int>(right);
            pendingNodes.push(rightChild);
            front->right = rightChild;
        }
    }

    return root;
}

void print(BinaryTreeNode<int>* root)
{
    if(root == NULL)
    {
        return;
    }

    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);

    while(pendingNodes.size()!=0)
    {
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();

        if(front == NULL)
        {
            cout<<endl;

            if(!pendingNodes.empty())
            {
                pendingNodes.push(NULL);
            }
        }

        else
        {
            cout << front->data << ":";
            cout << "L:";

            if(front->left)
            {
                pendingNodes.push(front->left);
                cout << front->left->data << ",";
            }
            else
            {
                cout << -1 << ",";
            }

            cout << "R:";

            if(front->right)
            {
                pendingNodes.push(front->right);
                cout << front->right->data << endl;
            }
            else
            {
                cout << -1 << endl;
            }
        }
    }
}

void countHelper(BinaryTreeNode<int>* root, int &count)
{
    if(root == NULL)
    {
        return;
    }

    countHelper(root->left, count);

    if(root->left == NULL && root->right == NULL)
    {
        count++;
    }

    countHelper(root->right, count);
}

int count(BinaryTreeNode<int>* root)
{
    int count = 0;
    countHelper(root, count);
    return count;
}

int main()
{
    BinaryTreeNode<int> *root = takeInput();
    print(root);

    cout << "The number of leaf nodes in the binary tree are : " << count(root);
}
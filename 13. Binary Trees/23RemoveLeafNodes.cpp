#include<iostream>
#include<bits/stdc++.h>
#include<math.h>
#include<cstdlib>
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

        cout << "Enter the left child of " << front->data << " : ";
        int leftChildData;
        cin >> leftChildData;

        if(leftChildData!=-1)
        {
            BinaryTreeNode<int> *leftChild = new BinaryTreeNode<int>(leftChildData);
            pendingNodes.push(leftChild);
            front->left = leftChild;
        }

        cout << "Enter the right child of " << front->data << " : ";
        int rightChildData;
        cin >> rightChildData;

        if(rightChildData!=-1)
        {
            BinaryTreeNode<int> *rightChild = new BinaryTreeNode<int>(rightChildData);
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

BinaryTreeNode<int>* removeLeafNodes(BinaryTreeNode<int>* root)
{
    if(root == NULL)
    {
        return root;
    }

    if(root->left == NULL || root->right == NULL)
    {
        return NULL;
    }

    root->left = removeLeafNodes(root->left);
    root->right = removeLeafNodes(root->right);
    return root;
}

int main()
{
    BinaryTreeNode<int> *root = takeInput();
    print(root);

    BinaryTreeNode<int> *newRoot = removeLeafNodes(root);
    cout << "The updated binary tree is : " << endl;
    print(root);
}
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

void printTree(BinaryTreeNode<int>* root)
{
    
}
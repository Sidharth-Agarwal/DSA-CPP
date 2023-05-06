#include<iostream>
#include"0BinaryTreeNode.h"

using namespace std;

BinaryTreeNode<int>* takeInput()
{
    int rootData;
    cout << "Enter data : ";
    cin >> rootData;

    if(rootData == -1)
    {
        return NULL;
    }

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    BinaryTreeNode<int> *leftChild = takeInput();
    BinaryTreeNode<int> *rightChild = takeInput();

    root->left = leftChild;
    root->right = rightChild;

    return root;
}

int main()
{
    BinaryTreeNode<int> *root = takeInput();
    //printTree(root);
}
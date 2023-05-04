#include<iostream>
#include"0BinaryTreeNode.h"

using namespace std;

int main()
{
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(10);
    BinaryTreeNode<int>* node1 = new BinaryTreeNode<int>(20);
    BinaryTreeNode<int>* node2 = new BinaryTreeNode<int>(30);

    root->left = node1;
    root->right = node2;

    cout << root->data;
    cout << endl;
    cout << root->left->data;
    cout << endl;
    cout << root->right->data;
}
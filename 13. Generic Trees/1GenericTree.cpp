#include<iostream>
#include<vector>
#include"0TreeNode.h"

using namespace std;

void printTree(TreeNode<int>* root)
{
    // This is an edge case and not a base case
    // This is only used when the tree root is given NULL
    if(root==NULL)
    {
        return;
    }
    
    cout << root->data << " : ";

    for (int i = 0; i < root->children.size(); i++)
    {
        cout << root->children[i]->data << " ";
    }

    cout << endl;

    for (int i = 0; i < root->children.size(); i++)
    {
        printTree(root->children[i]);
    }
}

int main()
{
    TreeNode<int> *root = new TreeNode<int>(10);
    TreeNode<int> *node1 = new TreeNode<int>(20);
    TreeNode<int> *node2 = new TreeNode<int>(30);

    root->children.push_back(node1);
    root->children.push_back(node2);

    printTree(root);
}
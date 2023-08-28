#include<iostream>
#include<vector>
#include"0TreeNode.h"

using namespace std;

TreeNode<int>* takeInput()
{
    int data;
    cout << "Enter data : ";
    cin >> data;

    TreeNode<int> *root = new TreeNode<int>(data);

    int n;
    cout << "Enter the number of children of " << root->data << " : ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
       TreeNode<int>* child = takeInput();
       root->children.push_back(child);
    }

    return root;
}

void printTree(TreeNode<int>* root)
{
    cout << root->data << " : ";

    for (int i = 0; i < root->children.size(); i++)
    {
       cout << root->children[i]->data<<" ";
    }

    cout << endl;

    for (int i = 0; i < root->children.size(); i++)
    {
       printTree(root->children[i]);
    }
}

int main()
{
    TreeNode<int> *root = takeInput();

    printTree(root);
}

// 1 3 2 2 5 0 6 0 3 0 4 1 7 0
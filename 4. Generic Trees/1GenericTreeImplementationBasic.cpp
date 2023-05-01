#include<iostream>
#include "0TreeNode.h"

using namespace std;

int mian()
{
    TreeNode<int>* root = new TreeNode<int>(1);
    TreeNode<int>* node1 = new TreeNode<int>(2);
    TreeNode<int>* node2 = new TreeNode<int>(3);

    root->children.push_back(node1);
    root->children.push_back(node2);

    cout << root->data;
    cout << endl;
    cout << node1->data;
    cout << endl;
    cout << node2->data;
}
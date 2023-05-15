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

void leftViewHelper(BinaryTreeNode<int>* root, vector<int> ans, int level)
{
    if(root == NULL)
    {
        return;
    }

    leftViewHelper(root->left, ans, level + 1);
    leftViewHelper(root->right, ans, level + 1);

    if(level == ans.size())
    {
        ans.push_back(root->data);
    }
}

vector<int> leftView(BinaryTreeNode<int>* root)
{
    vector<int> ans;
    leftViewHelper(root, ans, 0);
    return ans;
}

void solve(BinaryTreeNode<int>* root, vector<int> &ans, int level) {
    //base case
    if(root == NULL)
        return;
       
    //we entered into a new level    
    if(level == ans.size())
        ans.push_back(root->data);
        
    solve(root->left, ans, level+1);
    solve(root->right, ans, level+1);
}

vector<int> leftView(BinaryTreeNode<int> *root)
{
   vector<int> ans;
   solve(root, ans, 0);
   return ans;
}

int main()
{
    BinaryTreeNode<int> *root = takeInput();
    print(root);

    vector<int> ans = leftView(root);

    cout << "The left view of the given binary tree is : ";
    for (int i=0; i < ans.size();i++)
    {
        cout << i << " ";
    }
}
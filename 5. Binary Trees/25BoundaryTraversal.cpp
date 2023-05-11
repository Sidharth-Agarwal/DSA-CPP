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

void leftPart(BinaryTreeNode<int>* root, vector<int>&ans)
{
    if((root == NULL) || (root->left == NULL && root->right == NULL))
    {
        return;
    }

    ans.push_back(root->data);

    if(root->left)
    {
        leftPart(root->left, ans);
    }
    else
    {
        leftPart(root->right, ans);
    }
}

void leafNodes(BinaryTreeNode<int>* root, vector<int>&ans)
{
    if(root == NULL)
    {
        return;
    }

    if(root->left == NULL && root->right == NULL)
    {
        ans.push_back(root->data);
    }

    leafNodes(root->left,ans);
    leafNodes(root->right,ans);
}

void rightPart(BinaryTreeNode<int>* root, vector<int>&ans)
{
    if((root == NULL) || (root->left == NULL && root->right == NULL))
    {
        return;
    }

    if(root->right)
    {
        rightPart(root->right, ans);
    }
    else
    {
        rightPart(root->left, ans);
    }

    ans.push_back(root->data);
}

vector<int> boundaryTraversal(BinaryTreeNode<int>* root)
{
    vector<int> ans;

    if(root == NULL)
    {
        return ans;
    }

    ans.push_back(root->data);

    // Traversing the left part
    leftPart(root->left, ans);

    // Traversing the leaf nodes
    // in leaf and right sub-tree individually
    leafNodes(root->left, ans);
    leafNodes(root->right, ans);

    // Traversing the right part
    rightPart(root->right, ans);

    return ans;
}

int main()
{
    BinaryTreeNode<int> *root = takeInput();
    print(root);

    vector<int> ans = boundaryTraversal(root);

    cout << "The boundary traversal of the binary tree is : ";
    for (int i = 0; i < ans.size();i++)
    {
        cout << ans[i] << " ";
    }
}
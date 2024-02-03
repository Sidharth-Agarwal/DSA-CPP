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

vector<int> zigZagTraversal(BinaryTreeNode<int>* root)
{
    vector<int> result;

    if(root == NULL)
    {
        return result;
    }

    queue<BinaryTreeNode<int> *> level;
    level.push(root);

    bool leftToRight = true;

    while(!level.empty())
    {
        // Temporary vector for a particular level
        int size = level.size();
        vector<int> ans(size);

        // Level Processing
        for (int i = 0; i < size;i++)
        {
            BinaryTreeNode<int> *front = level.front();
            level.pop();

            int index = leftToRight ? i : size - i - 1;
            ans[index] = front->data;

            if(front->left)
            {
                level.push(front->left);
            }

            if(front->right)
            {
                level.push(front->right);
            }
        }

        // Direction change
        leftToRight = !leftToRight;

        // Updating the result vector
        for(auto i:ans)
        {
            result.push_back(i);
        }
    }

    return result;
}

int main()
{
    BinaryTreeNode<int> *root = takeInput();
    print(root);

    vector<int> zigZag = zigZagTraversal(root);

    cout << "The zig-zag traversal of the binary tree is : ";
    for (int i = 0; i < zigZag.size();i++)
    {
        cout << zigZag[i] << " ";
    }
}
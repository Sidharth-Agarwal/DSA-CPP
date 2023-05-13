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

vector<int> bottomView(BinaryTreeNode<int>* root)
{
    vector<int> ans;

    if(root == NULL)
    {
        return ans;
    }

    map<int, int> bootomNode;
    queue<pair<BinaryTreeNode<int> *, int>> pendingNodes;

    pendingNodes.push(make_pair(root, 0));

    while(!pendingNodes.empty())
    {
        pair<BinaryTreeNode<int> *, int> temp = pendingNodes.front();
        pendingNodes.pop();

        BinaryTreeNode<int> *front = temp.first;
        int horizontalDistance = temp.second;

        bootomNode[horizontalDistance] = front->data;

        if(front->left)
        {
            pendingNodes.push(make_pair(front->left, horizontalDistance - 1));
        }

        if(front->right)
        {
            pendingNodes.push(make_pair(front->right, horizontalDistance + 1));
        }
    }

    for(auto i:bootomNode)
    {
        ans.push_back(i.second);
    }

    return ans;
}

int main()
{
    BinaryTreeNode<int> *root = takeInput();
    print(root);

    vector<int> ans = bottomView(root);

    cout << "The bottom view of the given binary tree is : ";
    for(auto i:ans)
    {
        cout << i << " ";
    }
}
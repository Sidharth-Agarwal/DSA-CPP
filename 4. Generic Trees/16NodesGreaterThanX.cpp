#include<iostream>
#include<queue>
#include<vector>
#include"0TreeNode.h"

using namespace std;

TreeNode<int>* takeInput()
{
    int data;
    cout << "Enter the root data : ";
    cin >> data;

    TreeNode<int> *rootData = new TreeNode<int>(data);

    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(rootData);

    while(pendingNodes.size()!=0)
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();

        int num;
        cout << "Enter the number of childeren of " << front->data << " : ";
        cin >> num;

        for (int i = 0; i < num; i++)
        {
            int nodeData;
            cout << "Enter the " << i << "th child node data of " << front->data << " : ";
            cin >> nodeData;

            TreeNode<int> *child = new TreeNode<int>(nodeData);
            pendingNodes.push(child);
            front->children.push_back(child);
        }
    }

    return rootData;
}

void printTree(TreeNode<int>* root)
{
    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);

    while(pendingNodes.size()!=0)
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();

        cout << front->data << " : ";

        for (int i = 0; i < front->children.size(); i++)
        {
            if (i < front->children.size()-1)
            {
                cout << front->children[i]->data<<",";
            }
            else
            {
                cout << front->children[i]->data;
            }

            pendingNodes.push(front->children[i]);
        }

        cout << endl;
    }
}

int greaterNodes(TreeNode<int>* root, int node)
{
    int count = 0;

    if(root->data > node)
    {
        count = 1;
    }
    else
    {
        count = 0;
    }

    for(int i=0;i<root->children.size();i++)
    {
        count += greaterNodes(root->children[i],node);
    }

    return count;
}

int main()
{
    TreeNode<int> *root = takeInput();
    printTree(root);
}
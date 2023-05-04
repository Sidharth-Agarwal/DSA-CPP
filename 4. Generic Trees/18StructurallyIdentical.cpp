#include<iostream>
#include<vector>
#include<queue>
#include"0TreeNode.h"

using namespace std;

TreeNode<int>* takeInput()
{
    int data;
    cout << "Enter the root data : ";
    cin >> data;

    TreeNode<int> *root = new TreeNode<int>(data);

    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);

    while(pendingNodes.size()!=0)
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();

        int num;
        cout << "Enter the number of children of " << front->data << " : ";
        cin >> num;

        for (int i = 0; i < num; i++)
        {
            int node;
            cout << "Enter the " << i << "th child node of " << front->data << " : ";
            cin >> node;

            TreeNode<int> *child = new TreeNode<int>(node);
            pendingNodes.push(child);
            front->children.push_back(child);
        }
    }

    return root;
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
            if(i<front->children.size()-1)
            {
                cout << front->children[i]->data << ",";
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

int main()
{
    TreeNode<int> *root = takeInput();
    printTree(root);
}
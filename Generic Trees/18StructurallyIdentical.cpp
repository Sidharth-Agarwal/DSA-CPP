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

bool areIdentical(TreeNode<int> *root1, TreeNode<int> *root2)
{
    if(root1 == NULL && root2 == NULL)
    {
        return true;
    }

    if((root1 == NULL && root2 != NULL) || (root1 != NULL && root2 == NULL))
    {
        return false;
    }

    if((root1->data != root2->data) || (root1->children.size() != root2->children.size()))
    {
        return false;
    }

    for (int i = 0; i < root1->children.size(); i++)
    {
        TreeNode<int> *child1 = root1->children[i];
        TreeNode<int> *child2 = root2->children[i];

        if(!areIdentical(child1,child2))
        {
            return false;
        }
    }

    return true;
}

int main()
{
    cout << "Enter the data of the first tree";
    cout << endl;
    TreeNode<int> *root1 = takeInput();

    cout << "Enter the data of the second tree";
    cout << endl;
    TreeNode<int>* root2 = takeInput();

    if(areIdentical(root1,root2))
    {
        cout << "The trees are identical";
    }
    else
    {
        cout << "The tree are not identical";
    }
}
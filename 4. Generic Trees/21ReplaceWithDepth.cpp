#include<iostream>
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

    while(pendingNodes.size() != 0)
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();

        int num;
        cout << "Enter the number of the chilren of " << front->data << " : ";
        cin >> num;

        for (int i = 0; i < num; i++)
        {
            int childData;
            cout << "Enter the " << i << "th child of the " << front->data << " : ";
            cin >> childData;

            TreeNode<int> *child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }

    return root;
}

void printTree(TreeNode<int>* root)
{
    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);

    while(pendingNodes.size() != 0)
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();

        for (int i = 0; i < front->children.size();i++)
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

void printLevelAtNewLine(TreeNode<int>* root)
{
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    pendingNodes.push(NULL);

    while(pendingNodes.size() != 0)
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();

        if(front == NULL)
        {
            if(pendingNodes.empty())
            {
                break;
            }

            pendingNodes.push(NULL);
            cout << endl;
            continue;
        }

        cout << front->data << " ";

        for (int i = 0; i < front->children.size();i++)
        {
            pendingNodes.push(front->children[i]);
        }
    }
}

// void replaceWithDepthHelper(TreeNode<int> *root, int depth)
// {
//     root->data = depth;

//     for(int i=0; i<root->children.size();i++)
//     {
//         replaceWithDepthHelper(root->children[i],depth+1);
//     }
// }

// void replaceWithDepthValue(TreeNode<int> *root)
// {
//     if(root == NULL)
//     {
//         return;
//     }

//     replaceWithDepthHelper(root,0);
// }

void replaceWithDepthHelper(TreeNode<int> *root, int depth)
{
    root->data = depth;

    for (int i = 0; i < root->children.size();i++)
    {
        replaceWithDepthHelper(root->children[i], depth + 1);
    }
}

void replaceWithDepth(TreeNode<int>* root)
{
    if(root == NULL)
    {
        return;
    }

    replaceWithDepthHelper(root, 0);
}

int main()
{
    TreeNode<int> *root = takeInput();
    replaceWithDepth(root);
    printLevelAtNewLine(root);
}
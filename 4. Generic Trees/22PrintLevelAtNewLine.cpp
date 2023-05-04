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
        cout << "Enter the number of children of " << front->data << " : ";
        cin >> num;

        for (int i = 0; i < num;i++)
        {
            int child;
            cout << "Enter the " << i << "th node of " << front->data << " : ";
            cin >> child;

            TreeNode<int> *childNode = new TreeNode<int>(child);
            front->children.push_back(childNode);
            pendingNodes.push(childNode);
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

int main()
{
    TreeNode<int> *root = takeInput();

    cout << "The entered tree is as follows - ";
    cout << endl;
    printTree(root);
    cout << endl;
    cout << "Tree in level at new line form is as follows - ";
    cout << endl;
    printLevelAtNewLine(root);
}
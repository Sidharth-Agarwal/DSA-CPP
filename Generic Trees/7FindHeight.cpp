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

        for (int i = 0; i < num;i++)
        {
            int childData;
            cout << "Enter " << i << " th child of " << front->data << " : ";
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

int height(TreeNode<int>* root)
{
    int ans = 0;

    for (int i = 0; i < root->children.size(); i++)
    {
        int childHeight = height(root->children[i]);

        if (childHeight > ans)
        {
            ans = childHeight;
        }
    }

    return ans + 1;
}

int main()
{
    TreeNode<int> *root = takeInput();

    printTree(root);

    cout << endl;

    cout << "Height of the tree is : " << height(root);
}

// 1 3 2 3 4 2 5 6 0 1 7 0 0 0

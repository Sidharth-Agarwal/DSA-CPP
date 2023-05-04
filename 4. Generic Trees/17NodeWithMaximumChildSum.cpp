#include<iostream>
#include<queue>
#include<vector>
#include<climits>
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

template<typename T>
class MaxNodePair
{
    public:
    TreeNode<T> *node;
    int sum;
};

MaxNodePair<int>* maxSumNodeHelper(TreeNode<int>* root)
{
    if(root == NULL)
    {
        MaxNodePair<int> *pair = new MaxNodePair<int>();
        pair->node = NULL;
        pair->sum = INT_MIN;
        return pair;
    }

    int sum = root->data;

    for (int i = 0; i < root->children.size(); i++)
    {
        sum += root->children[i]->data;
    }

    MaxNodePair<int>* ans = new MaxNodePair<int>();
    ans->node = root;
    ans->sum = sum;

    for (int i = 0; i < root->children.size();i++)
    {
        MaxNodePair<int> *childAns = maxSumNodeHelper(root->children[i]);

        if(childAns->sum > ans->sum)
        {
            ans = childAns;
        }
    }

    return ans;
}

TreeNode<int>* maxSumNode(TreeNode<int>* root)
{
    return maxSumNodeHelper(root)->node;
}

int main()
{
    TreeNode<int> *root = takeInput();

    TreeNode<int> *ans = maxSumNode(root);
    
    cout << "The maximum child sum of a node is : " << ans->data;
}
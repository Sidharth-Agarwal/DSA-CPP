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
class SecondLargestReturnType
{
    public:
    TreeNode<int> *largest;
    TreeNode<int> *secondLargest;

    SecondLargestReturnType(TreeNode<int>* largest, TreeNode<int>* secondLargest)
    {
        this->largest = largest;
        this->secondLargest = secondLargest;
    }
};

SecondLargestReturnType<int>* getSecondLargestNodeHeleper(TreeNode<int>* root)
{
    if(root == NULL)
    {
        return new SecondLargestReturnType<int>(NULL, NULL);
    }

    SecondLargestReturnType<int> *ans = new SecondLargestReturnType<int>(root, NULL);

    for(int i=0;i<root->children.size();i++)
    {
        SecondLargestReturnType<int> *childAns = getSecondLargestNodeHeleper(root->children[i]);

        if(childAns->largest->data > ans->largest->data)
        {
            if(childAns->secondLargest == NULL)
            {
                ans->secondLargest = ans->largest;
                ans->largest = childAns->largest;
            }

            else
            {
                if(childAns->secondLargest->data > ans->largest->data)
                {
                    ans->secondLargest = childAns->secondLargest;
                    ans->largest = childAns->largest;
                }

                else
                {
                    ans->secondLargest = ans->largest;
                    ans->largest = childAns->largest;
                }
            }
        }

        else
        {
            if(ans->largest->data!=childAns->largest->data && 
            (ans->secondLargest == NULL || childAns->largest->data > ans->secondLargest->data))
            {
                ans->secondLargest = childAns->largest;
            }
        }
    }
    return ans;
}

TreeNode<int>* getSecondLargestNode(TreeNode<int>* root)
{
    return getSecondLargestNodeHeleper(root)->secondLargest;
}

int main()
{
    TreeNode<int> *root = takeInput();
}
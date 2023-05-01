#include<iostream>
#include<vector>

using namespace std;

template<typename T>
class TreeNode
{
    public:
    T data;
    vector<TreeNode<T> *> children;

    TreeNode(T data)
    {
        this->data = data;
    }

    ~TreeNode()
    {
        for (int i = 0; i < children.size(); i++)
        {
            delete children[i];
        }
    }
};

void printTree(TreeNode<int>* root)
{
    cout << root->data << endl;

    for (int i = 0; i < root->children.size(); i++)
    {
        printTree(root->children[i]);
    }
}

int main()
{
    TreeNode<int> *root = new TreeNode<int>(10);
    TreeNode<int> *child1 = new TreeNode<int>(20);
    TreeNode<int> *child2 = new TreeNode<int>(30);
    root->children.push_back(child1);
    root->children.push_back(child2);
}
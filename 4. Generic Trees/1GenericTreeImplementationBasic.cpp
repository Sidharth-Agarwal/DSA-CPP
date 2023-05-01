#include<iostream>
#include<vector>

using namespace std;

template<typename T>
class Node
{
    public:
    T data;
    vector<Node<T>*> children;

    Node(T data)
    {
        this->data = data;
    }

    ~Node()
    {
        for (int i = 0; i < children.size();i++)
        {
            delete children[i];
        }
    }
};

void printTree(Node<int>* root)
{
    cout << root->data << endl;

    for (int i = 0; i < root->children.size();i++)
    {
        printTree(root->children[i]);
    }
}

int main()
{
    Node<int> *root = new Node<int>(10);
    Node<int> *child1 = new Node<int>(20);
    Node<int> *child2 = new Node<int>(30);
    root->children.push_back(child1);
    root->children.push_back(child2);
}
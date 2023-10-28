// Write program using functions for binary tree traversals: Pre-order, In-order and Postorder using recursive approach
#include <iostream>

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        data = d;
        left = right = NULL;
    }
};

Node *buildTree(Node *root)
{
    std::cout << "Enter the data" << std::endl;
    int data;
    std::cin >> data;
    if (data == -1)
    {
        return NULL;
    }
    root = new Node(data);
    std::cout << "Enter the left data for node " << data << std::endl;
    root->left = buildTree(root->left);
    std::cout << "Enter the right data for node " << data << std::endl;
    root->right = buildTree(root->right);
    return root;
}

void preOrder(Node *root)
{
    // base case
    if (root == NULL)
        return;
    std::cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node *root)
{
    // base case
    if (root == NULL)
        return;
    inOrder(root->left);
    std::cout << root->data << " ";
    inOrder(root->right);
}

void postOrder(Node *root)
{
    // base case
    if (root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    std::cout << root->data << " ";
}

int main()
{
    Node *root = NULL;
    // 1 3 4 -1 -1 9 -1 -1 7 5 -1 -1 -1
    root = buildTree(root);
    preOrder(root);
    std::cout << std::endl;
    postOrder(root);
    std::cout << std::endl;
    inOrder(root);
    return 0;
}
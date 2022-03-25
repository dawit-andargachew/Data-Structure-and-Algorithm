#include <iostream>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};

// returns a new node
node *create_node(int val) // return new node
{
    node *newNode = new node;
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// inserts new node to the Binary Tree
node *insert(node *root, int val)
{
    if (root == NULL)
        return create_node(val);

    if (root->data < val)
        root->right = insert(root->right, val);

    else if (root->data > val)
        root->left = insert(root->left, val);
    return root;
}

// preorder Binary Tree Traversal
void print_Preorder(node *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    print_Preorder(root->left);
    print_Preorder(root->right);
}

int main()
{
    // sample data
    node *root = NULL;
    root = insert(root, 10);
    root = insert(root, 6);
    root = insert(root, 15);
    root = insert(root, 4);
    root = insert(root, 8);
    root = insert(root, 7);
    root = insert(root, 14);
    root = insert(root, 11);
    root = insert(root, 12);
    root = insert(root, 13);
    root = insert(root, 18);
    root = insert(root, 16);
    root = insert(root, 17);
    root = insert(root, 19);

    print_Preorder(root);
    return 0;
}
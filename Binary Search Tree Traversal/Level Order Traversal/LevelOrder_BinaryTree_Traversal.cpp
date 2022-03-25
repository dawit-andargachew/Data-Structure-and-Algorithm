#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;

    node *right;
    node *left;

    node(int a)
    {
        data = a;
        right = NULL;
        left = NULL;
    }
};

node *insert_node(node *root, int x)
{
    // If leaf is encountered
    if (root == NULL)
    {
        node *temp = new node(x);
        return temp;
    }
    // Recur for left subtree
    if (root->data > x)
    {
        root->left = insert_node(root->left, x);
    }
    // Recur for right subtree
    else
    {
        root->right = insert_node(root->right, x);
    }
    return root;
}

//print elements in there level
void printLevelOrder(node *root)
{

    if (root == NULL)
        return;

    // Create an empty queue for level order traversal
    queue<node *> q;

    // Enqueue Root and initialize height
    q.push(root);

    while (q.empty() == false)
    {
        // Print front of queue and remove it from queue
        node *element = q.front();
        cout << element->data << " ";
        q.pop();

        // Enqueue left child
        if (element->left != NULL)
            q.push(element->left);

        // Enqueue right child
        if (element->right != NULL)
            q.push(element->right);
    }
}
int main()
{
    node *root = NULL;

// sample data inserted in the binary tree
    root = insert_node(root, 10); 
    root = insert_node(root, 6);
    root = insert_node(root, 15);
    root = insert_node(root, 4);
    root = insert_node(root, 8);
    root = insert_node(root, 7);
    root = insert_node(root, 14);
    root = insert_node(root, 12);
    root = insert_node(root, 11);
    root = insert_node(root, 13);
    root = insert_node(root, 18);
    root = insert_node(root, 16);
    root = insert_node(root, 17);
    root = insert_node(root, 19);

    printLevelOrder(root);

    return 0;
}
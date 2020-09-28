#include <iostream>

using namespace std;

typedef struct Node
{
    /* data */
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *createNode(int data)
{
    Node *node = new Node;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
}

Node *insert(Node *root, int data)
{
    /* if root == NULL, create new Node and assign data */
    if (root == NULL)
    {
        root = createNode(data);
        return root;
    }

    /* if data < root->data */
    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, data);
    }

    return root;
}

void inOrder(Node *root)
{
    /* if node is null return */
    if (root == NULL)
        return;

    /* Traverse the left sub tree */
    inOrder(root->left);
 
    /* print the value */
    cout << root->data << ", ";
 
    /* Traverse the right sub tree */
    inOrder(root->right);
}

void preOrder(Node *root)
{
    /* if node is null return */
    if (root == NULL)
        return;

    /* print the value */
    cout << root->data << ", ";

    /* Traverse the left sub tree */
    preOrder(root->left);    
 
    /* Traverse the right sub tree */
    preOrder(root->right);
}

void postOrder(Node *root)
{
    /* if node is null return */
    if (root == NULL)
        return;

    /* Traverse the left sub tree */
    postOrder(root->left);
 
    /* Traverse the right sub tree */
    postOrder(root->right);

    /* print the value */
    cout << root->data << ", ";
}

void freeMemory(Node *node)
{
    if (node == NULL)
    {
        return;
    }

    /* Traverse left sub tree and free */
    freeMemory(node->left);

    /* Traverse right sub tree and free */
    freeMemory(node->right);

    /* Free node data by delete */
    delete node;
}

int main()
{
    Node *root = NULL;

    root = insert(root, 60);
    root = insert(root, 40);
    root = insert(root, 20);
    root = insert(root, 10);
    root = insert(root, 30);
    root = insert(root, 50);
    root = insert(root, 80);
    root = insert(root, 70);
    root = insert(root, 90);

    cout << "In-order traversal binary search tree: " << endl;
    inOrder(root);

    cout << "\nPre-order traversal binary search tree: " << endl;
    preOrder(root);

    cout << "\nPost-order traversal binary search tree " << endl;
    postOrder(root);

    freeMemory(root);
    cout << "=== END ===" << endl;
    return 0;
}
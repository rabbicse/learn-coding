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
    if(root == NULL)
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
    cout << root->data << ", " << endl;
    /* Traverse the right sub tree */
    inOrder(root->right);
}

int main()
{
    Node* root = NULL;

    root = insert(root, 60);
    root = insert(root, 40);
    root = insert(root, 20);
    root = insert(root, 10);
    root = insert(root, 30);
    root = insert(root, 50);
    root = insert(root, 80);
    root = insert(root, 70);
    root = insert(root, 90);

    inOrder(root);


    cout << "Hello" << endl;
    return 0;
}
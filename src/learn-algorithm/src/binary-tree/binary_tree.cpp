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

Node *searchMin(Node *node)
{
    if (node == NULL || node->data == 0)
        return NULL;

    if (node->left == NULL)
        return node;

    return searchMin(node->left);
}

Node *searchMax(Node *node)
{
    if (node == NULL || node->data == 0)
        return NULL;

    if (node->right == NULL)
        return node;

    return searchMax(node->right);
}

Node *deleteNode(Node *node, int data)
{
    if (node == NULL)
        return node;

    /* if data is less than node data, search node to left and delete it */
    if (data < node->data)
    {
        node->left = deleteNode(node->left, data);
    }
    /* if data is greater than node data, search node to right and delete it */
    else if (data > node->data)
    {
        node->right = deleteNode(node->right, data);
    }

    /* found the data and it has left and right node so remove*/
    else if (node->left != NULL && node->right != NULL)
    {
        /* Find the minimum node of the right subtree to replace the current node*/
        Node* minNode = searchMin(node->right);

        /* Set min node data of right child to current*/
        node->data = minNode->data;

        /* update right node replace all children data as right child data changed*/
        node->right = deleteNode(node->right, node->data);
    }
    /* found the data and it has left or right node so remove*/
    else
    {
        node = node->left != NULL ? node->left : node->right;
    }

    return node;
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

    cout << "\nMin " << endl;
    Node *minValue = searchMin(root);
    cout << minValue->data;

    cout << "\nMax " << endl;
    Node *maxValue = searchMax(root);
    cout << maxValue->data;

    cout << "\nRemove node: 10 " << endl;
    root = deleteNode(root, 10);
    inOrder(root);

    cout << "\nRemove node: 20 " << endl;
    root = deleteNode(root, 20);
    inOrder(root);

    cout << "\nRemove node: 40 " << endl;
    root = deleteNode(root, 40);
    inOrder(root);

    freeMemory(root);

    cout << "\n=== END ===" << endl;
    return 0;
}
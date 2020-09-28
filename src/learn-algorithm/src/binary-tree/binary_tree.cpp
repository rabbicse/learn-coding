#include <iostream>

using namespace std;

typedef struct Node
{
    /* data */
    int data;
    struct Node* left;
    struct Node* right;
} Node;

int main()
{
    cout << "Hello" << endl;
    return 0;
}
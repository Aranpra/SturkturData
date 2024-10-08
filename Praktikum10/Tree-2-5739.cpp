#include <iostream>
using namespace std;

struct node
{
    char data;
    node *left;
    node *right;
};

node *root = NULL;

void addNode(node **root, char isi)
{
    if ((*root) == NULL)
    {
        node *baru;
        baru = new node;
        baru->data = isi;
        baru->left = NULL;
        baru->right = NULL;
        (*root) = baru;
    }
}

void preOrder(node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

void postOrder(node *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
}

int main()
{
    char isinya;
    printf("\n\n\n              Posisi Awal Binary Tree:               \n\n\n");
    printf("------------------A M I K Z J-----------------\n");

    // level 0
    addNode(&root, isinya = 'A');
    // Level 1
    addNode(&root->left, isinya = 'M');
    addNode(&root->right, isinya = 'I');
    // level 2
    addNode(&root->left->left, isinya = 'K');
    addNode(&root->right->right, isinya = 'Z');
    addNode(&root->right->right->left, isinya = 'J');

    cout << "\nPreOrder  : ";
    preOrder(root);
    cout << "\nInOrder   : ";
    inOrder(root);
    cout << "\nPostOrder : ";
    postOrder(root);

    return 0;
}

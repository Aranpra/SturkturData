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
    printf("\n\n\n  Posisi Awal Binary Tree:  \n\n\n");

    // level 1
    addNode(&root, isinya = 'A');
    // Level 2
    addNode(&root->left, isinya = 'M');
    addNode(&root->right, isinya = 'I');
    // level 3
    addNode(&root->left->left, isinya = 'K');
    addNode(&root->right->right, isinya = 'Z');
    addNode(&root->right->left, isinya = 'J');
    // level 4
    addNode(&root->left->left->left, isinya = 'O');
    addNode(&root->left->left->right, isinya = 'M');
    // level 5
    addNode(&root->left->left->left->left, isinya = 'Y');
    addNode(&root->left->left->left->right, isinya = 'K');
    
    cout << "            A" << endl;
    cout << "           / \\" << endl;
    cout << "          M   I" << endl;
	cout << "         /   / \\" << endl;
	cout << "        K   J   Z" << endl;
	cout << "       / \\    " << endl;
	cout << "      O   M " << endl;
	cout << "     / \\        " << endl;
	cout << "    Y   K      \n\n" << endl;
  
	cout << "PreOrder   : ";
    preOrder(root);
    cout << endl;
    
    cout << "InOrder    : ";
    inOrder(root);
    cout << endl;
    
    cout << "PostOrder  : ";
    postOrder(root);
    cout << endl;

    return 0;
}

#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node(int v)
    {
        val = v;
        left = nullptr;
        right = nullptr;
    }
};

Node *RightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;
    x->right = y;
    y->left = T2;
    return x;
}

Node *LeftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;
    y->left = x;
    x->right = T2;
    return y;
}

void preorder(Node *root)
{
    if (!root)
        return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    Node *root = new Node(30);
    root->left = new Node(20);
    root->right = new Node(40);
    root->left->left = new Node(10);
    root->right->right = new Node(50);

    cout << "tree before inserting 15: ";
    preorder(root);
    cout << endl;

    root->left->left->right = new Node(15);

    cout << "after inserting 15: ";
    preorder(root);
    cout << endl;

    root->left->left = LeftRotate(root->left->left);
    root->left = RightRotate(root->left);

    cout << "tree after balancing: ";
    preorder(root);
    cout << endl;

    return 0;
}

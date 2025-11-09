#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    int height;

    Node(int val)
    {
        data = val;
        left = right = nullptr;
        height = 1;
    }
};

class AVLTree
{
    Node *root;

    int getHeight(Node *node)
    {
        if (!node)
            return 0;
        return node->height;
    }

    int getBalance(Node *node)
    {
        if (!node)
            return 0;
        return getHeight(node->left) - getHeight(node->right);
    }

    void updateHeight(Node *node)
    {
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    }

    Node *rotateRight(Node *y)
    {
        Node *x = y->left;
        Node *T2 = x->right;
        x->right = y;
        y->left = T2;
        updateHeight(y);
        updateHeight(x);
        return x;
    }

    Node *rotateLeft(Node *x)
    {
        Node *y = x->right;
        Node *T2 = y->left;
        y->left = x;
        x->right = T2;
        updateHeight(x);
        updateHeight(y);
        return y;
    }

    Node *balance(Node *node)
    {
        int bf = getBalance(node);

        if (bf > 1 && getBalance(node->left) >= 0)
            return rotateRight(node);
        if (bf > 1 && getBalance(node->left) < 0)
        {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }
        if (bf < -1 && getBalance(node->right) <= 0)
            return rotateLeft(node);
        if (bf < -1 && getBalance(node->right) > 0)
        {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }

    Node *insert(Node *node, int val)
    {
        if (!node)
            return new Node(val);

        if (val < node->data)
            node->left = insert(node->left, val);
        else if (val > node->data)
            node->right = insert(node->right, val);
        else
            return node;

        updateHeight(node);
        return balance(node);
    }

    void preorder(Node *node)
    {
        if (!node)
            return;
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

public:
    AVLTree() { root = nullptr; }

    void insert(int val) { root = insert(root, val); }

    void displayPreorder()
    {
        preorder(root);
        cout << endl;
    }
};

int main()
{
    AVLTree tree;

    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);

    cout << "AVL tree before inserting 12: ";
    tree.displayPreorder();

    tree.insert(12);

    cout << "AVL tree after inserting 12: ";
    tree.displayPreorder();

    return 0;
}

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
        left = right = NULL;
        height = 1;
    }
};

class BST
{
    Node *root;

    int get_height(Node *node)
    {
        if (!node)
            return 0;
        return node->height;
    }

    int get_balance(Node *node)
    {
        if (!node)
            return 0;
        return get_height(node->left) - get_height(node->right);
    }

    void update_height(Node *node)
    {
        node->height = 1 + max(get_height(node->left), get_height(node->right));
    }

    Node *rotate_right(Node *y)
    {
        Node *x = y->left;
        Node *T2 = x->right;

        x->right = y;
        y->left = T2;

        update_height(y);
        update_height(x);

        return x;
    }

    Node *rotate_left(Node *x)
    {
        Node *y = x->right;
        Node *T2 = y->left;

        y->left = x;
        x->right = T2;

        update_height(x);
        update_height(y);

        return y;
    }

    Node *balance_node(Node *node)
    {
        int balance = get_balance(node);

        if (balance > 1 && get_balance(node->left) >= 0)
            return rotate_right(node);

        if (balance > 1 && get_balance(node->left) < 0)
        {
            node->left = rotate_left(node->left);
            return rotate_right(node);
        }

        if (balance < -1 && get_balance(node->right) <= 0)
            return rotate_left(node);

        if (balance < -1 && get_balance(node->right) > 0)
        {
            node->right = rotate_right(node->right);
            return rotate_left(node);
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

        update_height(node);
        return balance_node(node);
    }

    void inorder(Node *node)
    {
        if (!node)
            return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

public:
    BST() { root = NULL; }

    void insert(int val) { root = insert(root, val); }

    void left_rotate_root()
    {
        if (root)
            root = rotate_left(root);
    }

    void display()
    {
        inorder(root);
        cout << endl;
    }
};

int main()
{
    BST tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    cout << "AVL tree inorder before inserting 55: ";
    tree.display();

    tree.insert(55);
    cout << "After inserting 55: ";
    tree.display();

    tree.left_rotate_root();
    cout << "After left rotation on root: ";
    tree.display();

    return 0;
}

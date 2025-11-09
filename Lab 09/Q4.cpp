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
        left = nullptr;
        right = nullptr;
        height = 1;
    }
};

class AVLTree
{
    Node *root;

    int getHeight(Node *node)
    {
        if (node == nullptr)
        {
            return 0;
        }
        else
        {
            return node->height;
        }
    }

    void updateHeight(Node *node)
    {
        int leftHeight = getHeight(node->left);
        int rightHeight = getHeight(node->right);
        node->height = 1 + max(leftHeight, rightHeight);
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

    int getBalance(Node *node)
    {
        if (node == nullptr)
            return 0;
        return getHeight(node->left) - getHeight(node->right);
    }

    Node *balance(Node *node)
    {
        int bf = getBalance(node);

        if (bf > 1 && getBalance(node->left) >= 0)
        {
            return rotateRight(node);
        }

        if (bf > 1 && getBalance(node->left) < 0)
        {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        if (bf < -1 && getBalance(node->right) <= 0)
        {
            return rotateLeft(node);
        }

        if (bf < -1 && getBalance(node->right) > 0)
        {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }

    Node *insert(Node *node, int val)
    {
        if (node == nullptr)
        {
            Node *newNode = new Node(val);
            return newNode;
        }

        if (val < node->data)
        {
            node->left = insert(node->left, val);
        }
        else if (val > node->data)
        {
            node->right = insert(node->right, val);
        }
        else
        {
            return node;
        }

        updateHeight(node);
        return balance(node);
    }

    void inorder(Node *node, int &count, int k, int &result)
    {
        if (node == nullptr)
            return;

        inorder(node->left, count, k, result);

        count++;
        if (count == k)
        {
            result = node->data;
        }

        inorder(node->right, count, k, result);
    }

    void reverseInorder(Node *node, int &count, int k, int &result)
    {
        if (node == nullptr)
            return;

        reverseInorder(node->right, count, k, result);

        count++;
        if (count == k)
        {
            result = node->data;
        }

        reverseInorder(node->left, count, k, result);
    }

public:
    AVLTree()
    {
        root = nullptr;
    }

    void insert(int val)
    {
        root = insert(root, val);
    }

    int kthSmallest(int k)
    {
        int count = 0;
        int result = -1;
        inorder(root, count, k, result);
        return result;
    }

    int kthLargest(int k)
    {
        int count = 0;
        int result = -1;
        reverseInorder(root, count, k, result);
        return result;
    }

    int getLeftHeight()
    {
        if (root == nullptr)
            return 0;
        return getHeight(root->left);
    }

    int getRightHeight()
    {
        if (root == nullptr)
            return 0;
        return getHeight(root->right);
    }

    void displayInorder(Node *node)
    {
        if (node == nullptr)
            return;
        displayInorder(node->left);
        cout << node->data << " ";
        displayInorder(node->right);
    }

    void display()
    {
        displayInorder(root);
        cout << endl;
    }
};

int main()
{
    AVLTree tree;

    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    int k = 3;

    cout << k << " smallest: " << tree.kthSmallest(k) << endl;
    cout << k << " largest: " << tree.kthLargest(k) << endl;
    cout << "Left subtree height from root: " << tree.getLeftHeight() << endl;
    cout << "Right subtree height from root: " << tree.getRightHeight() << endl;

    return 0;
}

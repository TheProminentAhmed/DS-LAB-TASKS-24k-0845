
/*AVL trees are used to maintain balance in binary search trees ensuring operations like insertion, deletion, and search run in Ologn time.*/

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

    Node *A = new Node(10);
    A->left = new Node(6);
    A->left->left = new Node(4);
    A->left->right = new Node(8);

    cout << "BST A Preorder: ";
    preorder(A);
    cout << endl;

    cout << "AVL A Preorder: ";
    preorder(A);
    cout << endl;

    Node *B = new Node(10);
    B->right = new Node(16);
    B->right->left = new Node(12);
    B->right->right = new Node(18);

    cout << "\nBST B Preorder: ";
    preorder(B);
    cout << endl;

    B = LeftRotate(B);
    cout << "AVL B Preorder: ";
    preorder(B);
    cout << endl;

    return 0;
}
/*For tree A, the left side of 10 is too heavy, so we rotate right. 6 becomes the new root, 10 moves to the right, and 8 stays between them.

For tree B, the right side of 10 is too heavy, so we rotate left. 16 becomes the new root, 10 goes to the left, and 12 stays in the middle. Now both trees are balanced.*/

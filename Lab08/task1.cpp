#include <iostream>

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BST {
private:
    Node* root;
    Node* insertHelper(Node* node, int val) {
        if (!node) return new Node(val);
        if (val < node->data) node->left = insertHelper(node->left, val);
        else node->right = insertHelper(node->right, val);
        return node;
    }
    Node* deleteHelper(Node* node, int val) {
        if (!node) return nullptr;
        if (val < node->data) node->left = deleteHelper(node->left, val);
        else if (val > node->data) node->right = deleteHelper(node->right, val);
        else {
            if (!node->left) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (!node->right) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            Node* temp = minValueNode(node->right);
            node->data = temp->data;
            node->right = deleteHelper(node->right, temp->data);
        }
        return node;
    }
    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current && current->left) current = current->left;
        return current;
    }
    bool searchHelper(Node* node, int val) {
        if (!node) return false;
        if (node->data == val) return true;
        return val < node->data ? searchHelper(node->left, val) : searchHelper(node->right, val);
    }
    void inorderHelper(Node* node) {
        if (node) {
            inorderHelper(node->left);
            std::cout << node->data << " ";
            inorderHelper(node->right);
        }
    }
    void preorderHelper(Node* node) {
        if (node) {
            std::cout << node->data << " ";
            preorderHelper(node->left);
            preorderHelper(node->right);
        }
    }
    void postorderHelper(Node* node) {
        if (node) {
            postorderHelper(node->left);
            postorderHelper(node->right);
            std::cout << node->data << " ";
        }
    }
public:
    BST() : root(nullptr) {}
    void insert(int val) { root = insertHelper(root, val); }
    void deleteVal(int val) { root = deleteHelper(root, val); }
    bool search(int val) { return searchHelper(root, val); }
    void inorder() { inorderHelper(root); std::cout << std::endl; }
    void preorder() { preorderHelper(root); std::cout << std::endl; }
    void postorder() { postorderHelper(root); std::cout << std::endl; }
};

int main() {
    BST bst;
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    std::cout << "Inorder: ";
    bst.inorder();
    std::cout << "Preorder: ";
    bst.preorder();
    std::cout << "Postorder: ";
    bst.postorder();

    std::cout << "Search 40: " << (bst.search(40) ? "Found" : "Not Found") << std::endl;
    bst.deleteVal(20);
    std::cout << "After deleting 20, Inorder: ";
    bst.inorder();

    return 0;
}

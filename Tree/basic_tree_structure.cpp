#include <bits/stdc++.h>   // Includes all standard C++ libraries
using namespace std;

/*
   Node class represents a single node of a Binary Tree
*/
class Node {
public:
    int data;          // Value stored in the node
    Node *left;        // Pointer to left child
    Node *right;       // Pointer to right child

    // Constructor to initialize node
    Node(int value) {
        data = value;
        left = right = NULL;   // Initially no children
    }
};

/*
   Preorder Traversal (Root → Left → Right)
*/
void preorder(Node* root) {
    if (root == NULL) {
        return;    // Base case: empty tree
    }
    cout << root->data << " "; // Visit root
    preorder(root->left);      // Traverse left subtree
    preorder(root->right);     // Traverse right subtree
}

/*
   Inorder Traversal (Left → Root → Right)
*/
void inorder(Node* root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);       // Traverse left subtree
    cout << root->data << " "; // Visit root
    inorder(root->right);      // Traverse right subtree
}

/*
   Postorder Traversal (Left → Right → Root)
*/
void postorder(Node* root) {
    if (root == NULL) {
        return;
    }
    postorder(root->left);     // Traverse left subtree
    postorder(root->right);    // Traverse right subtree
    cout << root->data << " "; // Visit root
}

/*
   Function to create a Binary Tree using recursion
   - User enters node value
   - -1 indicates no node (NULL)
*/
Node* Binarytree() {
    int x;
    cin >> x;

    // If input is -1, return NULL (no node)
    if (x == -1) {
        return NULL;
    }

    // Create a new node
    Node* temp = new Node(x);

    // Recursively create left subtree
    cout << "Enter the left child of " << x << ": " << endl;
    temp->left = Binarytree();

    // Recursively create right subtree
    cout << "Enter the right child of " << x << ": " << endl;
    temp->right = Binarytree();

    return temp;
}

int main() {
    cout << "Enter the node value: " << endl;

    // Root of the binary tree
    Node* root = Binarytree();

    // Display traversals
    cout << "Pre Order: ";
    preorder(root);

    cout << "\nIn Order: ";
    inorder(root);

    cout << "\nPost Order: ";
    postorder(root);

    return 0;
}

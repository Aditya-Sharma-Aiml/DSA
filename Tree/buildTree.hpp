#ifndef BUILD_TREE_HPP
#define BUILD_TREE_HPP

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int d){
        data = d;
        left = right = NULL;
    }
};
class Tree {
public:
    Node* buildTree() {
        cout << "Enter the data (-1 for NULL): ";
        int x;
        cin >> x;

        if (x == -1)
            return NULL;

        Node* root = new Node(x);

        cout << "Enter the data for the left child of " << x << endl;
        root->left = buildTree();
        cout << "Enter the data for the right child of " << x << endl;
        root->right = buildTree();

        return root;
    }

    Node* buildTree(Node* root) {

        cout << "Enter the data (-1 for NULL): ";
        int data;
        cin >> data;

        if(data == -1)
            return NULL;

        root = new Node(data);

        cout << "Enter the data for the left child of " << data << endl;
        root->left = buildTree(root->left);

        cout << "Enter the data for the right child of " << data << endl;
        root->right = buildTree(root->right);

        return root;
    }
};
#endif
#include "../include/Tree.h"
#include <iostream>
using namespace std;

Node::Node(int d) {
    data = d;
    left = right = NULL;
}

Node* buildTree() {
    int x;
    cin >> x;

    if (x == -1)
        return NULL;

    Node* root = new Node(x);

    root->left = buildTree();
    root->right = buildTree();

    return root;
}
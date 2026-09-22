#ifndef TREE_H
#define TREE_H

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int d);
};

Node* buildTree();

#endif
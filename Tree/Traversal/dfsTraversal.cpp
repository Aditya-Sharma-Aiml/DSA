#include "../buildTree.hpp"
#include <bits/stdc++.h>
using namespace std;



void preOrder(Node* root){

    if(root == nullptr) return;

    cout << root -> data << " ";
    preOrder(root -> left);
    preOrder(root -> right);    
    cout << endl;
}
void postOrder(Node* root){

    if(root == nullptr) return;

    postOrder(root -> left);
    postOrder(root -> right);    
    cout << root -> data << " ";
    cout << endl;
}
void inOrder(Node* root){

    if(root == nullptr) return;

    inOrder(root -> left);
    cout << root -> data << " ";
    inOrder(root -> right);    
    cout << endl;
}

int main(){
    Tree tree;
    Node* root = tree.buildTree(NULL);

    cout << "Preorder Traversal: ";
    cout << endl;
    preOrder(root);
    cout << endl;

    cout << "Inorder Traversal: ";
    cout << endl;
    inOrder(root);
    cout << endl;

    cout << "Postorder Traversal: ";
    cout << endl;
    postOrder(root);
    cout << endl;

    return 0;
}

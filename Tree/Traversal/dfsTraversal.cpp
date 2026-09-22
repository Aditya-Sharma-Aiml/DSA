
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

    Node* root = buildTree(NULL);

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

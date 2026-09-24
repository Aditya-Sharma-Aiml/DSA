#include "../buildTree.hpp"
#include<bits/stdc++.h>
using namespace std;

//Approach: identical tree ki tarah hi h root ko ignore krke left and right subtree ko mirror check krte hain like 
// identical tree : p->left == q->left and p->right == q->right
// BUT
// mirror tree : p->left == q->right and p->right == q->left


bool comapareMirror(Node* p, Node* q) {
    if (!p || !q) return p == q; // If either node is NULL, check if both are NULL (mirror) or not (not mirror)

    if (p->data != q->data) return false; // If the data of the current nodes are different, they are not mirrors

    // Recursively check left subtree of p with right subtree of q and right subtree of p with left subtree of q
    return comapareMirror(p->left, q->right) && comapareMirror(p->right, q->left);
}
bool isSymmetric(Node* root) {
    if (!root) return true; // An empty tree is symmetric

    // Check if the left and right subtrees are mirrors of each other
    return comapareMirror(root->left, root->right);
}

int main(){
    
    Tree tree;
    Node* root = tree.buildTree(NULL);

    if (isSymmetric(root)) {
        cout << "The tree is symmetric." << endl;
    } else {
        cout << "The tree is not symmetric." << endl;
    }

    return 0;
}
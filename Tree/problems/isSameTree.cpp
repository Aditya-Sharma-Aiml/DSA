#include "../buildTree.hpp"
#include<bits/stdc++.h>
using namespace std;

// Approach: we can commpare using preorder or postorder or inorder or level order traversal. Here we are using preorder traversal to compare the two trees. We will check if the data of the current nodes are the same and then recursively check the left and right subtrees.

bool isSameTree(Node* p, Node* q) {

    if (!p || !q) return p==q; // If either node is NULL, check if both are NULL (same tree) or not (different trees)

    if (p->data != q->data) return false; // If the data of the current nodes are different, the trees are not the same

    // Recursively check left and right subtrees
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

int main(){
    
    Tree tree;
    Node* root1 = tree.buildTree(NULL);

    Node* root2 = tree.buildTree(NULL);

    if (isSameTree(root1, root2)) {
        cout << "The two trees are the same." << endl;
    } else {
        cout << "The two trees are different." << endl;
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

class postOrderInorder {
public:

    struct Node {
        int data;
        Node* left;
        Node* right;

        Node(int val) : data(val), left(nullptr), right(nullptr) {}
    };

    Node* buildTreeHelper(vector<int>& postorder,
                          int postStart, int postEnd,
                          vector<int>& inorder,
                          int inStart, int inEnd,
                          unordered_map<int, int>& inorderIndexMap) {

        if (inStart > inEnd || postStart > postEnd)
            return nullptr;

        // Postorder ka last element = root
        Node* root = new Node(postorder[postEnd]);

        // Root ka index inorder mein
        int inRoot = inorderIndexMap[root->data];

        // Left subtree mein kitne nodes hain
        int numsLeft = inRoot - inStart;

        // Left subtree
        root->left = buildTreeHelper(
            postorder,
            postStart,
            postStart + numsLeft - 1,
            inorder,
            inStart,
            inRoot - 1,
            inorderIndexMap
        );

        // Right subtree
        root->right = buildTreeHelper(
            postorder,
            postStart + numsLeft,
            postEnd - 1,
            inorder,
            inRoot + 1,
            inEnd,
            inorderIndexMap
        );

        return root;
    }

    Node* buildTree(vector<int>& postorder, vector<int>& inorder) {

        unordered_map<int, int> inorderIndexMap;

        for (int i = 0; i < inorder.size(); i++)
            inorderIndexMap[inorder[i]] = i;

        int postStart = 0;
        int postEnd = postorder.size() - 1;

        int inStart = 0;
        int inEnd = inorder.size() - 1;

        return buildTreeHelper(
            postorder,
            postStart,
            postEnd,
            inorder,
            inStart,
            inEnd,
            inorderIndexMap
        );
    }
};
int main(){
    vector<int>postorder, inorder;
    int n;
    cin >> n;
    for(int i=0; i<n ; i++ ){
        int x;
        cin >> x;
        postorder.push_back(x);
    }
    for(int i=0; i<n ; i++ ){
        int x;
        cin >> x;
        inorder.push_back(x);
    }
}
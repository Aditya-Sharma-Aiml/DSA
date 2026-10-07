
#include <bits/stdc++.h>
using namespace std;

class PreorderInorder{
    public:
    // Approach: The buildTree function constructs a binary tree from the given preorder and inorder traversal sequences. It uses a recursive approach to build the tree by identifying the root node from the preorder sequence and finding its position in the inorder sequence to determine the left and right subtrees.
    // TC-> O(n) where n is the number of nodes in the binary tree. We visit each node once during the construction of the tree.
    // SC-> O(n) where n is the number of nodes in the binary tree. The space complexity is due to the recursive call stack and the storage of the inorder index map.

    struct Node {
        int data;
        Node* left;
        Node* right;
        Node(int val) : data(val), left(nullptr), right(nullptr) {}
    };

    Node* buildTreeHelper(vector<int>& preorder,int preStart,  int preEnd, vector<int>&inorder, int inStart, int inEnd, unordered_map<int, int>& inorderIndexMap) {
        if (inStart > inEnd || preStart > preEnd) {
            return nullptr; // Base case: no nodes to construct
        }

        Node* root = new Node(preorder[preStart]); // Create a new node with the current root value from preorder

        int inRoot = inorderIndexMap[root->data]; // Find the index of the root in the inorder sequence
        int numsLeft = inRoot - inStart; // Calculate the number of nodes in the left subtree

        // Recursively build the left and right subtrees
        root->left = buildTreeHelper(preorder, preStart, preStart + numsLeft, inorder, inStart, inRoot - 1, inorderIndexMap); // Build left subtree
        root->right = buildTreeHelper(preorder, preStart + numsLeft + 1, preEnd, inorder, inRoot + 1, inEnd, inorderIndexMap); // Build right subtree

        return root; // Return the constructed subtree rooted at 'root'
    }

    Node* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inorderIndexMap; // Map to store indices of inorder values
        for (int i = 0; i < inorder.size(); i++) {
            inorderIndexMap[inorder[i]] = i; // Fill the map with value-index pairs
        }
        int preStart = 0; // Initialize preorder index
        int preEnd = preorder.size(); // Initialize preorder end
        int inStart = 0; // Initialize inorder start
        int inEnd = inorder.size() - 1; // Initialize inorder end

        return buildTreeHelper(preorder, preStart, preEnd, inorder, inStart, inEnd, inorderIndexMap); // Start building the tree
    }
};
int main(){
    vector<int>preorder, inorder;
    int n;
    cin >> n;
    for(int i=0; i<n ; i++ ){
        int x;
        cin >> x;
        preorder.push_back(x);
    }
    for(int i=0; i<n ; i++ ){
        int x;
        cin >> x;
        inorder.push_back(x);
    }

    
}
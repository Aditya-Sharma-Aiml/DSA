#include "../buildTree.hpp"
#include<bits/stdc++.h>
using namespace std;

class LeftSideView {
    public:
        // Time Complexity: O(N) where N is the number of nodes in the binary tree, as we visit each node once and perform constant time operations for each node.
        // Space Complexity: O(N) where N is the number of nodes in the binary tree, as we use a queue to perform level order traversal and store nodes at each level.
        vector<int> leftSideViewBFS(Node* root) {
            vector<int> ans;
            if(!root) return ans;

            queue<Node*> q; // Queue to perform level order traversal
            q.push(root); // Start with the root

            while(!q.empty()){
                int size = q.size(); // Number of nodes at the current level

                for(int i = 0; i < size; i++){
                    Node* node = q.front(); // Get the front node in the queue
                    q.pop();

                    // If this is the first node of the current level, add it to the answer
                    if(i == 0){
                        ans.push_back(node->data);
                    }

                    // Add left and right children to the queue for the next level
                    if(node->left) q.push(node->left);
                    if(node->right) q.push(node->right);
                }
            }

            return ans;
        }

        // Time Complexity: O(N) where N is the number of nodes in the binary tree, as we visit each node once and perform constant time operations for each node.
        // Space Complexity: O(H) where H is the height of the binary tree, as we use recursion and the maximum depth of the recursion stack is H.

        void leftSideViewDFS(Node* root, vector<int>& ans, int level) {
            if(!root) return;

            // If this is the first node of the current level, add it to the answer
            if(level == ans.size()){
                ans.push_back(root->data);
            }

            // Recur for left and right children, increasing the level
            leftSideViewDFS(root->left, ans, level + 1);
            leftSideViewDFS(root->right, ans, level + 1);
        }

        vector<int> leftSideView(Node* root) {
            vector<int> ans;
            leftSideViewDFS(root, ans, 0);
            return ans;

        }
};


int main(){
    
    Tree tree;
    Node* root = tree.buildTree(NULL);

    LeftSideView leftSideViewObj;
    vector<int> result = leftSideViewObj.leftSideView(root);

    cout << "Left Side View of the Binary Tree: ";
    for(int val : result){
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
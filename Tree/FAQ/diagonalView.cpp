#include "../buildTree.hpp"
#include<bits/stdc++.h>
using namespace std;

// Approach: The right child remains on the same diagonal, while the left child moves to the next diagonal. 

// We use an array of arrays where we use diagonal number as row index and actual nodes as columns to group all same diagonal nodes together.

class DiagonalView {
    public:
        vector<int> diagonalViewBFS(Node* root) {
            vector<int> ans;
            if(!root) return ans;

            queue<Node*> q; // Queue to perform level order traversal
            q.push(root); // Start with the root

            while(!q.empty()){
                Node* node = q.front(); // Get the front node in the queue
                q.pop();

                // Traverse the diagonal and add nodes to the answer
                while(node){
                    ans.push_back(node->data); // Add the current node's data to the answer

                    // If there is a left child, add it to the queue for future processing
                    if(node->left) q.push(node->left);

                    // Move to the right child for diagonal traversal
                    node = node->right;
                }
            }

            return ans;
        }

        void diagonalViewDFS(Node* root, int diagonal, vector<vector<int>> &diagonals) {

                              
            if (root == nullptr)
                return;

            if (diagonal == diagonals.size())
                diagonals.push_back({});

            diagonals[diagonal].push_back(root->data);

            // Left child moves to the next diagonal
            diagonalViewDFS(root->left, diagonal + 1, diagonals);

            // Right child stays on the same diagonal
            diagonalViewDFS(root->right, diagonal, diagonals);


            }
            vector<int> diagonalView(Node* root) {
                vector<int> ans;
                vector<vector<int>> diagonals;

                diagonalViewDFS(root, 0, diagonals);

                for(const auto& diagonal : diagonals) {
                    for(int val : diagonal) {
                        ans.push_back(val);
                    }
                }
            return ans;
        }
};



int main(){
    
    Tree tree;
    Node* root = tree.buildTree(NULL);
    DiagonalView diagonalViewObj;

    vector<int> result = diagonalViewObj.diagonalView(root);

    cout << "Diagonal View of the Binary Tree (BFS): ";
    for(int val : result){
        cout << val << " ";
    }
    return 0;
}
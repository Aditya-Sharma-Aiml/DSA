#include "../buildTree.hpp"
#include <bits/stdc++.h>
using namespace std;

class NodeToNodePath {
    public:
        bool solve(Node* root, int target, vector<int>& path) {
            if (!root) return false;

            // Add the current node's data to the path
            path.push_back(root->data);

            // Check if the current node is the target
            if (root->data == target) {
                return true;
            }

            // Recursively check the left and right subtrees
            if (solve(root->left, target, path) || solve(root->right, target, path)) {
                return true;
            }

            // If the target is not found in either subtree, remove the current node from the path
            path.pop_back();
            return false;
        }
        vector<int>getPath(Node* A, int B){
            vector<int>ans;
            if(!A) return ans;

            solve(A, B, ans);

            return ans;
        }
};

// int main() {
//     Tree tree;
//     Node* root = tree.buildTree(NULL);

//     int target;
//     cout << "Enter the target node value: ";
//     cin >> target;

//     NodeToNodePath nodeToNodePathObj;

//     vector<int> path = nodeToNodePathObj.getPath(root, target);

//     cout << "Path to the target node: ";
//     for (int i = 0; i < path.size(); i++) {
//         cout << path[i] << " ";
//     }
//     cout << endl;

//     return 0;
// }
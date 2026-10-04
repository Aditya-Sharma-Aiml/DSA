#include "../buildTree.hpp"
#include <bits/stdc++.h>
using namespace std;

class MaxWidth{
    public:
    // Approach: The maximum width of a binary tree is the maximum number of nodes present at any level in the tree. 

    int maxWidth(Node* root){
        
        int ans = 0;

        if(!root) return ans;
        queue<pair<Node*, int>> q; // pair of node and its level
        q.push({root, 0}); // push root with level 0

        while(!q.empty()){
            int size = q.size();
            long long minIdx = q.front().second; // Store the minimum index at the current level to normalize indices and avoid overflow
            long long first, last; // To store the first and last node's index at the current level

            for(int i=0; i<size; i++){
                long long currIdx = q.front().second - minIdx; // Normalize the level to avoid overflow
                Node* node = q.front().first;
                q.pop();

                if(i == 0) first = currIdx; // First node at this level
                if(i == size - 1) last = currIdx; // Last node at this level

                if(node->left) q.push({node->left, currIdx * 2 + 1}); // Left child index
                if(node->right) q.push({node->right, currIdx * 2 + 2}); // Right child index
            }

            ans = max(ans, (int)(last - first + 1)); // Update maximum width
        }
        return ans;
    }
};

int main(){
    Tree t;
    Node* root = t.buildTree(NULL);

    MaxWidth mw;
    cout << "Maximum width of the binary tree: " << mw.maxWidth(root) << endl;

    return 0;
}
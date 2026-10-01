#include "../buildTree.hpp"
#include<bits/stdc++.h>
using namespace std;

class VerticalOrderTraversal {
    // x = -2
    //     y = 0 → {1}
    //     y = 1 → {2, 3}
    //     y = 2 → {4}
    // x = -1
    //     y = 0 → {5}
    //     y = 1 → {6, 7}
    // x = 0
    //     y = 0 → {8}
    //     y = 1 → {9, 10}
    // x = 1
    //     y = 0 → {11}
    //     y = 1 → {12, 13}
    // X = 2
    //     y = 0 → {14}
    //     y = 1 → {15, 16}
    
    public:
        vector<vector<int>> verticalOrderTraversal(Node* root) {
         
            vector<vector<int>> ans;
            if(!root) return ans;

            map<int, map<int, multiset<int>>>nodes; // Map to store nodes at each horizontal and vertical distance
            queue<pair<Node*, pair<int, int>>>  lq; // Queue to perform level order traversal, storing nodes along with their horizontal and vertical distances
            lq.push({root, {0, 0}}); // Start with the root

            while(!lq.empty()){

                auto p = lq.front(); // Get the front element of the queue
                lq.pop();

                Node* node = p.first; // Current node

                int x = p.second.first; // Horizontal distance
                int y = p.second.second; // Vertical distance
                
                nodes[x][y].insert(node->data); // Insert the node's data into the map at the corresponding distances

                if(node->left) lq.push({node->left, {x-1, y+1}}); // If left child exists, push it with updated distances

                if(node->right) lq.push({node->right, {x+1, y+1}}); // If right child exists, push it with updated distances
            }
            for(auto p: nodes){ // Iterate through the map to construct the answer
                vector<int> col;
                for(auto q: p.second){
                    col.insert(col.end(), q.second.begin(), q.second.end()); // Insert all nodes at the current distances into the column
                }
                ans.push_back(col); // Add the column to the answer
            }
            return ans;
        }


};

int main(){
    
    Tree tree;
    Node* root = tree.buildTree(NULL);

    VerticalOrderTraversal VOT;
    vector<vector<int>> result = VOT.verticalOrderTraversal(root);

    cout << "Vertical Order Traversal:" << endl;
    for (const auto& level : result) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
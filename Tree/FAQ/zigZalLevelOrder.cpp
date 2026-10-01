#include "../buildTree.hpp"
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> zigZagLevelOrder(Node* root) {
    vector<vector<int>> result;
    if (!root) return result;

    queue<Node*> q;
    q.push(root);
    bool leftToRight = true; // Flag to indicate the direction of traversal

    while (!q.empty()) {
        int size = q.size();
        vector<int> level(size);

        for (int i = 0; i < size; ++i) {
            Node* node = q.front();
            q.pop();

            // Determine the index based on the current direction
            int index = leftToRight ? i : (size - 1 - i);
            level[index] = node->data;


            // Add child nodes to the queue for the next level
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        //instead of using reverese indexing we can use deque to store the level values and push_back or push_front based on the direction or by reversing the array after the level is filled. But this approach is more efficient as it avoids the overhead of reversing or using a deque.

        if(leftToRight) {
            // If the current direction is left to right, we can directly add the level to the result
            result.push_back(level);
        } else {
            // If the current direction is right to left, we need to reverse the level before adding it to the result
            reverse(level.begin(), level.end());
            result.push_back(level);
        }

        // After processing the current level, flip the direction for the next level
        leftToRight = !leftToRight;
        result.push_back(level);
    }

    return result;
}
int main(){

    Tree tree;
    Node* root = tree.buildTree(NULL);

    vector<vector<int>> result = zigZagLevelOrder(root);

    cout << "Zigzag Level Order Traversal:" << endl;
    for (const auto& level : result) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int d){
        data = d;
        left = right = NULL;
    }
};

Node* buildTree(Node* root) {

    cout << "Enter the data (-1 for NULL): ";
    int data;
    cin >> data;

    if(data == -1)
        return NULL;

    root = new Node(data);

    cout << "Enter the data for the left child of " << data << endl;
    root->left = buildTree(root->left);

    cout << "Enter the data for the right child of " << data << endl;
    root->right = buildTree(root->right);

    return root;
}

// Algorithm
// Check whether the root is NULL; if so, the traversal is empty.

// Create a queue and place the root inside it because traversal begins from the first level.

// Remove the node at the front of the queue and process its value.

// Add its left child followed by its right child whenever those children exist.

// Continue removing and adding nodes until the queue becomes empty.

// Return the values in the order in which the nodes were processed.

// Time Complexity: O(N) because every node is inserted into and removed from the queue once.

// Space Complexity: O(W), where W is the maximum number of nodes present at any level.

vector<vector<int >> levelOrderTraversal(Node* root){
    vector<vector<int >> ans;
    if(!root) return ans; 

    queue<Node*>q;

    //initial push root to queue
    q.push(root);

    while(!q.empty()){

        // level array and its size
        int size = q.size();
        vector<int>level;

        for(int i=0; i<size; i++){

            Node* node = q.front();
            q.pop();

            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);

            level.push_back(node->data);

        }
        ans.push_back(level);
    }

    return ans;


}
int main(){

    Node* root = NULL;
    root = buildTree(root);
    vector<vector<int >> ans = levelOrderTraversal(root);
}
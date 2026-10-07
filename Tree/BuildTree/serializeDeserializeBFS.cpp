#include <bits/stdc++.h>
using namespace std;

class SerializeDeserializeBFS{
    public:
    // Approach: The serialize function converts a binary tree into a string representation using level-order traversal (BFS). The deserialize function reconstructs the binary tree from the serialized string representation. It uses a queue to facilitate the level-order traversal during serialization and deserialization.
    // TC-> O(n) where n is the number of nodes in the binary tree. We visit each node once during serialization and deserialization.
    // SC-> O(n) where n is the number of nodes in the binary tree. The space complexity is due to the storage of the serialized string and the queue used during deserialization.

    struct Node {
        int data;
        Node* left;
        Node* right;
        Node(int val) : data(val), left(nullptr), right(nullptr) {}
    };

    string serialize(Node* root) {
        if (!root) return ""; // Return empty string for null tree

        queue<Node*> q; // Queue for level-order traversal
        q.push(root); // Start with the root node

        string str;

        while(!q.empty()){

            Node* node = q.front();
            q.pop();

            if(node == nullptr){
                str.append("#,"); // Use '#' to represent null nodes

            } else {
                str.append(to_string(node->data) + ","); // Append current node's value
                q.push(node->left); // Enqueue left child
                q.push(node->right); // Enqueue right child
            }
        }

        return str;
    }
    Node* deserialize(string data) {
        if(data.empty()) return nullptr; // Return null for empty string

        stringstream ss(data);
        string str;
        getline(ss, str, ','); // Read the first value (root)

        Node* root = new Node(stoi(str)); // Create root node
        queue<Node*> q; // Queue for level-order reconstruction
        q.push(root); // Start with the root node

        while(!q.empty()){
            Node* node = q.front();
            q.pop();

            // Process left child
            if(getline(ss, str, ',')){
                if(str == "#"){
                    node->left = nullptr; // Left child is null
                } else {
                    node->left = new Node(stoi(str)); // Create left child
                    q.push(node->left); // Enqueue left child
                }
            }

            // Process right child
            if(getline(ss, str, ',')){
                if(str == "#"){
                    node->right = nullptr; // Right child is null
                } else {
                    node->right = new Node(stoi(str)); // Create right child
                    q.push(node->right); // Enqueue right child
                }
            }
        }

        return root; // Return the reconstructed tree's root
    }

};
int main(){

}
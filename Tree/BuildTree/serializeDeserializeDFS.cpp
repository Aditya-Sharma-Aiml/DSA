#include<bits/stdc++.h>
using namespace std;

class SerializeDeserializeDFS{
    public:
    // Approach: The serialize function converts a binary tree into a string representation using preorder traversal. The deserialize function reconstructs the binary tree from the serialized string representation. It uses a recursive approach to build the tree by reading values from the serialized string and creating nodes accordingly.
    // TC-> O(n) where n is the number of nodes in the binary tree. We visit each node once during serialization and deserialization.
    // SC-> O(n) where n is the number of nodes in the binary tree. The space complexity is due to the storage of the serialized string and the recursive call stack during deserialization.

    struct Node {
        int data;
        Node* left;
        Node* right;
        Node(int val) : data(val), left(nullptr), right(nullptr) {}
    };

    void serializeHelper(Node* root, string& out) {
        if (!root) {
            out += "# "; // Use '#' to represent null nodes
            return;
        }
        out += to_string(root->data) + " "; // Serialize current node
        serializeHelper(root->left, out); // Serialize left subtree
        serializeHelper(root->right, out); // Serialize right subtree
    }

    string serialize(Node* root) {
        string out; // Output stream to store serialized string
        serializeHelper(root, out); // Call helper function to perform serialization
        return out; // Return the serialized string
    }

    Node* deserializeHelper(string& data) {
        stringstream ss(data);
        string val;
        ss >> val; // Read next value from input stream
        if (val == "#") {
            return nullptr; // Return null for '#' representing null nodes
        }
        Node* root = new Node(stoi(val)); // Create new node with current value
        root->left = deserializeHelper(data); // Deserialize left subtree
        root->right = deserializeHelper(data); // Deserialize right subtree
        return root; // Return the constructed subtree rooted at 'root'
    }

    Node* deserialize(string& data) {
        return deserializeHelper(data); // Call helper function to perform deserialization
    }
};

int main(){
    SerializeDeserializeDFS s;
    SerializeDeserializeDFS::Node* root = new SerializeDeserializeDFS::Node(1);
    root->left = new SerializeDeserializeDFS::Node(2);
    root->right = new SerializeDeserializeDFS::Node(3);
    root->right->left = new SerializeDeserializeDFS::Node(4);
    root->right->right = new SerializeDeserializeDFS::Node(5);

    string serializedData = s.serialize(root);
    cout << "Serialized binary tree: " << serializedData << endl;

    SerializeDeserializeDFS::Node* deserializedRoot = s.deserialize(serializedData);
    string reserializedData = s.serialize(deserializedRoot);
    cout << "Reserialized binary tree after deserialization: " << reserializedData << endl;
    
}


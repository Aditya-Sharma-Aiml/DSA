#include<bits/stdc++.h>
using namespace std;
#include "../buildTree.hpp"

// Rule : 
// state 1 : Preorder , {node, 1} -> {node, 2} -> {node->left, 1}
// state 2 : Inorder , {node, 2} -> {node, 3} -> {node->right, 1}
// state 3 : Postorder 

vector<vector<int>>preInPostTraversal(Node* root){
    vector<vector<int>> ans(3);
    if(!root) return ans;

    stack<pair<Node*, int>> st;
    st.push({root, 1});

    while(!st.empty()){
        auto it = st.top();
        st.pop();

        Node* node = it.first;
        int state = it.second;

        if(state == 1){
            // Preorder: Process the node, then push left child
            ans[0].push_back(node->data);
            // Push the current node back with state 2 to process inorder next
            st.push({node, 2});
            // Push left child to stack for preorder traversal
            if(node->left) st.push({node->left, 1});
        }
        else if(state == 2){
            // Inorder: Process the node, then push right child
            ans[1].push_back(node->data);
            // Push the current node back with state 3 to process postorder next
            st.push({node, 3});
            // Push right child to stack for inorder traversal
            if(node->right) st.push({node->right, 1});
        }
        else{
            // Postorder: Process the node
            ans[2].push_back(node->data);
        }
    }

    return ans;
}

int main(){
    
    Tree  tree;
    Node* root = NULL;
    root = tree.buildTree(root);

    vector<vector<int>> ans = preInPostTraversal(root);

    cout << "Preorder: ";
    for(int i = 0; i < ans[0].size(); i++) {
        cout << ans[0][i] << " ";
    }
    cout << endl;

    cout << "Inorder: ";
    for(int i = 0; i < ans[1].size(); i++) {
        cout << ans[1][i] << " ";
    }
    cout << endl;

    cout << "Postorder: ";
    for(int i = 0; i < ans[2].size(); i++) {
        cout << ans[2][i] << " ";
    }
    cout << endl;

    
}
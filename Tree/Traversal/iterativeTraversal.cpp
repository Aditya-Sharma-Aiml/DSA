#include "../buildTree.hpp"
#include <bits/stdc++.h>
using namespace std;

// with stack root left right but push in reverse order right left so that left is processed first
vector<int> preOrder(Node* root){

    stack<Node*> st;
    vector<int> ans;

    //check if root is null
    if(root == nullptr) return ans;

    //initial push root to stack
    st.push(root);

    while(!st.empty()){
        //pop the top node from stack
        Node* node = st.top();
        st.pop();

        //process the node
        ans.push_back(node->data);

        //push right and left child to stack
        if(node->right) st.push(node->right);
        if(node->left) st.push(node->left);

    }
    return ans;
    
}

//using two stacks, first stack is used to store the nodes in reverse order of postorder traversal, and second stack is used to store the nodes in postorder traversal.

// if left child exists, push it to the first stack, and if right child exists, push it to the first stack. Then pop the top node from the first stack and push it to the second stack. Repeat this process until the first stack is empty. Finally, pop all nodes from the second stack and store their values in a vector.
vector<int> postOrderTwoStacks(Node* root){
    
    vector<int> ans;
    stack<Node*> st1, st2;

    if(root == nullptr) return ans;

    st1.push(root);

    while(!st1.empty()){

        Node* node= st1.top();
        st1.pop();

        st2.push(node);

        if(node->right) st1.push(node->right);
        if(node->left) st1.push(node->left);

    }

    // Pop all nodes from the second stack and store their values in a vector
    while(!st2.empty()){
        ans.push_back(st2.top()->data);
        st2.pop();
    }
    return ans;
    
}

vector<int> postOrderSingleStack(Node* root){

    vector<int> ans;
    stack<Node*> st;

    if(root == nullptr) return ans;

    Node* curr = root;

    while(curr != nullptr || !st.empty()){

        // Traverse the left subtree
        while(curr != nullptr){
            st.push(curr);
            curr = curr->left;
        }

        // Check the right subtree
        Node* temp = st.top()->right;

        if(temp == nullptr){
            temp = st.top();
            st.pop();
            ans.push_back(temp->data);

            // Check if the popped node is the right child of the top node in the stack
            while(!st.empty() && temp == st.top()->right){
                temp = st.top();
                st.pop();
                ans.push_back(temp->data);
            }
        } else {
            curr = temp;
        }
    }

    return ans;
}
vector<int> inOrder(Node* root){

    vector<int> ans;
    stack<Node*> st;
    Node* node = root;

    while(node != nullptr || !st.empty()){

        // Traverse the left subtree
        if(node != nullptr){
            st.push(node);
            node = node->left;
        }
        else {
            // If the left subtree is fully traversed, process the node and move to the right subtree
            if(st.empty()) break;

            // Pop the top node from the stack and process it
            node = st.top();
            st.pop();
            // Process the node
            ans.push_back(node->data);
            node = node->right;
        }

        
    }

    return ans;
}

int main(){
    vector<int> ans;
    Tree tree;
    Node* root = tree.buildTree(NULL);
    ans = inOrder(root);

    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;


    return 0;
}

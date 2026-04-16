#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* buildTree(Node* root){

    cout<<"Enter the data for the node: "<<endl;
    int data;
    cin>>data;

    root = new Node(data);

    if(data == -1){
        return NULL;
    }

    cout<<"for the left child of "<<data<<" ";
    root->left = buildTree(root->left);
    cout<<"for the right child of "<<data<<" ";
    root->right = buildTree(root->right);

    return root;
}

void levelOrderTraversal(Node* root){
    if(root == NULL){
        return;
    }

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        int size = q.size();

        for(int i=0; i<size; i++){
            Node* temp = q.front();
            q.pop();

            cout<<temp->data<<" ";

            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
        cout<<endl;
    }
}


int main(){
    Node* root = NULL;
    root = buildTree(root);
    levelOrderTraversal(root);
    return 0;
}


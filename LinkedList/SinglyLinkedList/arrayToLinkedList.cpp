#include<bits/stdc++.h>
using namespace std;

class Node{

    public:

    int data;
    Node* next;

    Node(int data){
        this->data = data;
        next = NULL;
    }
};

Node* arrayToLinkedList(vector<int>&nums){

    Node* head = new Node(nums[0]);
    Node* mover = head;

    for(int i=1; i<nums.size(); i++){

        Node* temp = new Node(nums[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}
void printList(Node* head){
    
    Node* curr = head;

    while(curr != nullptr){
        cout << curr->data << " " ;
        curr = curr -> next;
    }
    cout << endl;
}
void findLength(Node* head){

    Node* curr = head;
    int len = 0;
    while(curr != nullptr){
        len++;
        curr = curr -> next;
    }
    cout << "length is : " << len << endl;
}
void search(Node* head, int key){

    Node* curr = head;
    bool found = false;
    while(curr != nullptr){

        if(curr -> data == key) {
            found = true;
            break;
        }

        curr = curr -> next;
    }
    if (found)
        cout << key << " Found " << endl;
    else
        cout << key << " not Found " << endl;
}
int main(){

    vector<int>arr = {1,2,3,4,5,6,7};
    Node* head = arrayToLinkedList(arr);

    findLength(head);
    printList(head);

    int key = 0;
    search(head, key);

    
}
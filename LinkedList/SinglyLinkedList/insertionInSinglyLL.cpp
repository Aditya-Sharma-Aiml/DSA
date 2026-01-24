#include<bits/stdc++.h>
using namespace std;

struct Node{

    int data;
    Node* next;

    Node(int val){
        data = val;
        next = nullptr;
    }

    Node(int val , Node* next1){
        data = val;
        next = next1;
    }
    
};

class Solution{

    public:

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

    Node* insertAtHead(Node*head, int val){

        // Node* newNode= new Node(val); // called constructor with only data
        // newNode -> next = head;
        // return newNode;

        // Node* newNode = new Node(val, head);  // called constructor with next node
        // return newNode;

        return new Node(val, head);
    }

    Node* insertTail(Node* head, int val){
        if ( head== NULL){
            return new Node(val);
        }
        Node* temp = head;

        while(temp->next != NULL){ // we have to reach at last
            temp = temp -> next;
        }
        Node* newNode = new Node(val);
        temp -> next = newNode;
        return head;
    }
    Node* insertkth(Node* head, int val, int k){

        if(head == nullptr) {
            
            if(k==1){
                return new Node(val);
            }
            else{
                cout << k << "not exist" << endl;
                return NULL;
            }
        }
        if(k == 1){
            // return new Node(val, head);
            Node* newNode = new Node(val);
            newNode->next = head;
            return newNode;
        }

        Node* temp = head;
        int cnt = 0;

        while(temp != nullptr){

            cnt++;

            if(cnt == (k-1)){ // stop before the kth

                Node* newNode = new Node(val);
                newNode->next = temp->next;
                temp->next = newNode;
                break;
            }
            temp = temp->next;
        }
        return head;
    }
    Node* insertBeforeValue(Node* head, int element, int val){

        if(head == nullptr) {
            return nullptr; // jb koi node hi nhi hai toh kis value ke phle insert krun
        }
        if(head->data == val){
            // return new Node(element, head);
            Node* newNode = new Node(element);
            newNode->next = head;
            return newNode;
        }

        Node* temp = head;
        bool found = false;

        while(temp->next != nullptr){

            if(temp->next->data == val){ // stop before the kth

                Node* newNode = new Node(element);
                newNode->next = temp->next;
                temp->next = newNode;
                break;
            }
            temp = temp->next;
        }
        if(!found) cout << "value " << val << "not found" << endl;
        return head;
    }

};
int main(){

    vector<int>arr = {1,2,3,4,5,6,7,8};

    Solution sol;
    Node* head = sol.arrayToLinkedList(arr);
    cout << "before : ";
    sol.printList(head);

    head = sol.insertAtHead(head, 100);
    head = sol.insertTail(head, 200);
    head = sol.insertkth(head, 300, 4);
    head = sol.insertBeforeValue(head, 500, 300);

    cout<< "after : " ;
    sol.printList(head);

}
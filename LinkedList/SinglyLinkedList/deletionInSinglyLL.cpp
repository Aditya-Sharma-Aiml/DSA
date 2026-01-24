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

    Node* deleteHead(Node* head){

        if(head==NULL) {
            return head;
        }

        Node* temp = head;
        head = head->next;
        free(temp);
        return head;

    }

    Node* deleteTail(Node* head){

        if(head==NULL || head->next == NULL) {
            return NULL;
        }
        Node* temp = head;

        while(temp->next->next != NULL){

            temp = temp->next;
        }
        delete temp->next;
        temp ->next = NULL;

        return head;

    }


    Node* deleteKth(Node* head, int k){

        if(head==NULL) return NULL;

        if(k==1){ // first element or exist only one node in LL
            Node* temp = head;
            head = head->next;
            delete temp;
            return head;

        }

        int cnt = 0;
        Node* prev = NULL;
        Node* curr = head;

        while(curr != nullptr){

            cnt++;

            if(cnt==k){

                prev->next = prev -> next -> next; // prev -> next = curr -> next;
                delete curr;
                break;
            }
            prev = curr;
            curr = curr -> next;
        }
        return head;

    }
    Node* deleteValue(Node* head, int value){

        if(head==NULL) return NULL;

        if(head->data == value){ 
            Node* temp = head;
            head = head->next;
            delete temp;
            return head;

        }

        Node* prev = NULL;
        Node* curr = head;

        while(curr != nullptr){

            if(curr -> data == value){

                prev -> next = curr -> next;
                delete curr;
                break;
            }
            prev = curr;
            curr = curr -> next;
        }
        return head;
    }
};
int main(){

    vector<int>arr = {1,2,3,4,5,6,7,8};

    Solution sol;
    Node* head = sol.arrayToLinkedList(arr);
    cout << "before : ";
    sol.printList(head);

    head = sol.deleteHead(head);
    head = sol.deleteTail(head);
    head = sol.deleteKth(head, 3);
    head = sol.deleteValue(head, 6);
    cout<< "after : " ;
    sol.printList(head);

}
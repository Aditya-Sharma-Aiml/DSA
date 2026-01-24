#include<iostream>
#include<vector>
using namespace std;

class Node{

    public:

    Node* prev;
    int data;
    Node* next;

    Node(int val){
        prev = nullptr;
        data = val;
        next = nullptr;

    }

    Node(int val, Node* prev , Node* next){

        data = val;
        this->prev = prev;
        this->next = next;
    }

};

class Solution{

    public:

    Node* arrayToList(vector<int>&arr){

        if(arr.empty()) return nullptr;

        Node* head = new Node(arr[0]);

        Node* tail = head;

        for(int i = 1; i < arr.size(); ++i){
            // Node* newNode = new Node(arr[i]);
            // newNode->prev = tail;
            // tail->next = newNode;
            // tail = newNode;

            Node* newNode = new Node(arr[i], tail, nullptr);
            tail->next = newNode;
            tail = newNode;
        }
        return head;
    }
    void printList(Node* head){

        cout <<"null";
        while(head != nullptr){

            cout  << " <==> " << head->data;
            head = head->next;
        }
        cout <<" <==> null";

    }

    // delete head 
    Node* deleteHead(Node* head){

        if(head == NULL || head->next == NULL) return NULL;

        Node* temp = head;
        head = head->next;

        temp->next = NULL;
        head->prev = NULL;

        delete temp;

        return head;

    }
    // delete tail 
    Node* deleteTail(Node* head){

        // If list is empty
        if (head == NULL) return NULL;

        // If only one node present
        if (head->next == NULL) {
            delete head;
            return NULL;
        }

        Node* tail = head;

        while(tail->next != NULL){
            tail = tail->next;
        }

        // Node* temp = tail-> prev;
        // temp->next = NULL;
        // tail->prev = NULL;

        // Update second last node's next to NULL
        tail->prev->next = NULL;

        // Delete tail node
        delete tail;

        // Return head
        return head;;

    }
    // delete kth node 
    Node* deleteKth(Node* head, int k){

        // If list is empty or invalid k
        if (head == NULL || k <= 0) return head;

        Node* temp = head;
        int cnt = 0;

        while (temp != nullptr) {
            cnt++;
            if (cnt == k) break;
            temp = temp->next;
        }

        // k > length
        if (temp == NULL) return head;

        Node* backward = temp->prev;
        Node* forward  = temp->next;

        // only one node
        if (forward == NULL && backward == NULL) {
            delete temp;
            return NULL;
        }
        // delete head
        else if (backward == NULL) {
            return deleteHead(head);
        }
        // delete tail
        else if (forward == NULL) {
            return deleteTail(head);
        }
        // delete middle node
        else {
            backward->next = forward;
            forward->prev = backward;
            delete temp;
        }

        return head;
    }

    // delete the given node but that node can't be head
    void deleteNode(Node* node){

        Node* backward = node->prev;
        Node* forward = node->next;

        if(forward == NULL){

            backward -> next = NULL;
            node -> prev = NULL;
            delete node;
            return ;
        }

        backward -> next = forward;
        forward -> prev = backward;

        node->next = node->prev = NULL;
        delete node;
    }

};
int main(){

    Solution sol;

    vector<int>arr = {1,2,3,4,5,6,7};
    Node* head = sol.arrayToList(arr);
    cout <<"Before : ";
    sol.printList(head);
    cout << endl;



    head = sol.deleteHead(head);
    head = sol.deleteTail(head);
    head = sol.deleteKth(head, 2);
    sol.deleteNode(head->next->next->next);

    cout <<"After : ";
    sol.printList(head);

    return 0;
}

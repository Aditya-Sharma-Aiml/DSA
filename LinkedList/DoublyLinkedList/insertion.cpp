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
    
    // xxxxxxxxxxx insert Before xxxxxxxxxxxx
    
    // insert before head
    Node* insertBeforehead(Node* head, int val){

        Node* newNode = new Node(val , nullptr, head);

        if(head==nullptr) return newNode;
        head->prev = newNode;

        return newNode;

    }

    // insert before tail
    Node* insertBeforeTail(Node* head, int val){

        if(head->next == NULL) return insertBeforehead(head, val);

        Node* tail = head;

        while(tail->next != NULL){
            tail = tail -> next;
        }

        Node* back = tail->prev;

        Node* newNode = new Node(val, back, tail);

        back->next = newNode;
        tail->prev = newNode;

        return head;
    }

    // insert before kth node
    Node* insertBeforeKth(Node* head, int val, int k){

        if(k==1){
            return insertBeforehead(head, val);
        }

        Node* temp = head ;
        int cnt = 0;

        while(temp != NULL){
            cnt++;
            if(cnt ==k) break;
            temp = temp->next;
        }

        // k> length of ll
        if(temp == nullptr) return head;

        Node* back = temp->prev;

        Node* newNode = new Node(val);

        newNode->prev = back;
        newNode->next = temp;
        back->next = newNode;
        temp->prev = newNode;

        return head;
    }

    // insert before given node but not before head(we don't want to change head)

    void insertBeforeNode(Node* node, int val){

        Node* back = node->prev;
        Node* newNode= new Node(val, back, node);
        back->next = newNode;
        node->prev = newNode;

    }


    // ================= INSERT AFTER  =================

    // insert after head
    Node* insertAfterHead(Node* head, int val){

        if(head == nullptr) return head;

        Node* front = head->next;
        Node* newNode = new Node(val, head, front);

        head->next = newNode;
        if(front != nullptr){
            front->prev = newNode;
        }

        return head;
    }

    // insert after tail
    Node* insertAfterTail(Node* head, int val){

        if(head == nullptr) return new Node(val);

        Node* tail = head;
        while(tail->next != nullptr){
            tail = tail->next;
        }

        Node* newNode = new Node(val, tail, nullptr);
        tail->next = newNode;

        return head;
    }

    // insert after kth node
    Node* insertAfterKth(Node* head, int val, int k){

        if(head == nullptr || k <= 0) return head;

        Node* temp = head;
        int cnt = 0;

        while(temp != nullptr){
            cnt++;
            if(cnt == k) break;
            temp = temp->next;
        }

        if(temp == nullptr) return head;

        Node* front = temp->next;
        Node* newNode = new Node(val, temp, front);

        temp->next = newNode;
        if(front != nullptr){
            front->prev = newNode;
        }

        return head;
    }

    // insert after given node
    void insertAfterNode(Node* node, int val){

        if(node == nullptr) return;

        Node* front = node->next;
        Node* newNode = new Node(val, node, front);

        node->next = newNode;
        if(front != nullptr){
            front->prev = newNode;
        }
    }

};
int main(){

    Solution sol;

    vector<int>arr = {1,2,3,4,5,6,7};
    Node* head = sol.arrayToList(arr);
    cout <<"Before : ";
    sol.printList(head);
    cout << endl;

    head = sol.insertBeforehead(head, 10);
    head = sol.insertAfterHead(head, 11);
    head = sol.insertBeforeTail(head, 20);    
    head = sol.insertAfterTail(head, 21);
    head = sol.insertBeforeKth(head, 30, 3);
    head = sol.insertAfterKth(head, 31, 4);

    sol.insertBeforeNode(head->next->next, 100);
    sol.insertAfterNode(head->next->next, 200);

    cout <<"After : ";
    sol.printList(head);

    return 0;
}
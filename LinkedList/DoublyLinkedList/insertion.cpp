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

};
int main(){

    Solution sol;

    vector<int>arr = {1,2,3,4,5,6,7};
    Node* head = sol.arrayToList(arr);
    cout <<"Before : ";
    sol.printList(head);
    cout << endl;

    head = sol.insertBeforehead(head, 10);
    head = sol.insertBeforeTail(head, 20);
    head = sol.insertBeforeKth(head, 30, 3);
    sol.insertBeforeNode(head->next->next->next->next, 200);

    cout <<"After : ";
    sol.printList(head);

    return 0;
}

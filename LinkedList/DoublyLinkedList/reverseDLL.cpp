#include<iostream>
#include<vector>
#include<stack>
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

    // ========= bruteForce (time -> O(N) , space-> O(N)) ==============
    Node* reverseDLLusingStack(Node* head){
        // If list is empty or has only one node, return as-is
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        // Stack to store node data
        stack<int> st;

        // Pointer to traverse the list
        Node* temp = head;

        // Push all node values to stack
        while (temp != nullptr) {
            st.push(temp->data);
            temp = temp->next;
        }

        // Reset temp to head for second pass
        temp = head;

        // Replace node values with those from stack
        while (temp != nullptr) {
            temp->data = st.top();
            st.pop();
            temp = temp->next;
        }

        // Return head of reversed list
        return head;

    }

    // ========= Optimal (time -> O(N) , space-> O(1)) ==============

    Node* reverseDLL(Node* head){
        // vimp to handle with Dll no node and single node
        if(head == NULL || head->next == NULL) return head;

        // apply swapping of link like swappinng of two variable(a,b)
        Node* temp = NULL;
        Node* curr = head;

        while(curr != NULL){

            temp = curr->prev;       //  temp = a
            curr->prev = curr->next; //  a=b
            curr->next = temp;       //  b=temp
            //becoz next become prev and prev become next so move ahead by prev
            curr = curr->prev;

        }
        //temp stop before last node so
        Node* newHead = temp->prev;

        return newHead;

    }

};
int main(){

    Solution sol;

    vector<int>arr = {1,2,3,4,5};
    Node* head = sol.arrayToList(arr);

    cout << "Before : " ;
    sol.printList(head);
    cout << endl;

    head = sol.reverseDLL(head);
    // head = sol.reverseDLLusingStack(head); 

    cout << "After : " ;
    sol.printList(head);
    cout << endl;

    return 0;
}

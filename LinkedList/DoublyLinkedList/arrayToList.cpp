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

};
int main(){

    Solution sol;

    vector<int>arr = {1,2,3,4,5,6,7};
    Node* head = sol.arrayToList(arr);
    sol.printList(head);

    return 0;
}

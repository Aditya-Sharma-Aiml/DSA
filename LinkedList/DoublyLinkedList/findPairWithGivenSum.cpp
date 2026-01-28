#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int x) : data(x), prev(NULL), next(NULL) {}
};

Node* findTail(Node* head){
    Node* tail = head;
    while(tail && tail->next) tail = tail->next;
    return tail;
}

vector<pair<int,int>> findPairs(Node* head, int x) {
    vector<pair<int,int>> ans;
    if(!head) return ans;

    Node* left = head;
    Node* right = findTail(head);

    while(left && right && left != right && right->next != left) {
        int sum = left->data + right->data;

        if(sum == x){
            ans.push_back({left->data, right->data});
            left = left->next;
            right = right->prev;
        }
        else if(sum < x){
            left = left->next;
        }
        else{
            right = right->prev;
        }
    }
    return ans;
}

Node* arrayToDLL(const vector<int>& arr) {
    if(arr.empty()) return NULL;
    Node* head = new Node(arr[0]);
    Node* curr = head;
    for(int i = 1; i < arr.size(); i++){
        Node* newNode = new Node(arr[i]);
        curr->next = newNode;
        newNode->prev = curr;
        curr = newNode;
    }
    return head;
}

void printPairs(const vector<pair<int,int>>& v) {
    for(auto &p : v)
        cout << "(" << p.first << ", " << p.second << ") ";
    cout << endl;
}

int main() {

    vector<int> arr = {1, 2, 4, 5, 6, 8, 9};
    int target = 7;

    Node* head = arrayToDLL(arr);

    cout << "Pairs summing to " << target << ": ";
    vector<pair<int,int>> result = findPairs(head, target);
    printPairs(result);

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

// xxxxxxxxxxxxx similar as finding length of cycle  xxxxxxxxxxxx

class Node {
  public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class Solution {
  public:
    void removeLoop(Node* head) {
        
        Node* slow = head;
        Node* fast = head;
        
        while(fast && fast->next){
            
            slow = slow -> next;
            fast = fast -> next -> next;
            
            if(slow == fast) break;
        }
        
        if(!fast || !fast->next) return  ; // no cycle

        
        slow = head;
        
        // // don't do => 
        // // kronki ye fail krega 
        // //jb cycle first node (slow bhi yahi fast bhi yahi)
        // //fir dono sath me move krenge pe form hi rhi hogi 
        // // we will lose the connection of list 
        // //because after iteration slow and fast same node pe honge
        // // 1 → 2 → 3 → 4
        // // ↑           ↓
        // // └───────────┘

        // while(slow->next != fast -> next){
        //     slow = slow -> next;
        //     fast = fast -> next;
        // }
        // fast->next = NULL;
        
        
        // so first meet at common node
        while(slow!= fast){ 
            slow = slow -> next;
            fast = fast -> next;
        }
        
        // then slow ko fast ke ek piche tk le jake link tod do
        while(slow->next!= fast ){
            slow = slow -> next;
        }
        slow -> next = NULL;

    }
};

// utility to print list (safe: no loop)
void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {

    // create list: 1 -> 2 -> 3 -> 4
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    // create loop: 4 -> 2
    head->next->next->next->next = head->next;

    Solution sol;

    cout << "Before removing loop (limited print):\n";
    Node* temp = head;
    for(int i = 0; i < 10 && temp; i++) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "...\n";

    sol.removeLoop(head);

    cout << "\nAfter removing loop:\n";
    printList(head);

    return 0;
}

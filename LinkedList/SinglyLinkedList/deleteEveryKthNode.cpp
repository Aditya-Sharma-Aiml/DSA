#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};

class Solution {
  public:
    Node* deleteK(Node* head, int k) {

        if(!head || k==1) return NULL;
        
        Node* curr = head;

        int cnt=1;
        
        while(curr && curr->next){
            
            if(cnt==k-1){ // kth ko delete krna hai toh k-1th pe ruko 
                
                Node* delNode = curr -> next;
                curr-> next = curr -> next -> next;
                delete delNode;
                cnt = 1;
            }
            else{
                cnt++;
            }
            curr = curr ->next;
            
        }
        return head;

    }

    void printList(Node* head){

        Node* temp = head;
        while(temp){

            cout << temp->data << "->";
            temp = temp -> next;
        }
        cout << endl;
    }
};

int main(){

    Solution sol;

    Node* head = new Node(1);
    head -> next = new Node(2);
    head -> next -> next = new Node(3);
    head -> next -> next -> next= new Node(4);
    head -> next -> next -> next -> next = new Node(5);
    head -> next  -> next -> next -> next -> next = new Node(6);
    head -> next  -> next -> next -> next -> next -> next = new Node(7);

    int k = 3;

    cout << "original : ";
    sol.printList(head);
    
    head = sol.deleteK(head, k);
    
    cout << "After deleting every kth node : ";
    sol.printList(head);

}
#include<iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
}; 

class Solution {
  public:
    Node* removeDuplicates(Node* head) {

        if (!head || !head->next) return head;

        Node* temp = head;
        
        while (temp && temp->next) {

            if (temp->data == temp->next->data) {

                Node* delNode = temp->next;
                temp->next = temp->next->next;
                delete delNode;      
        
            } else {
                temp = temp->next;
            }
        }
        return head;
    }
};

// Utility function to print linked list
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Creating sorted linked list: 1 -> 1 -> 2 -> 3 -> 3 -> 4
    Node* head = new Node(1);
    head->next = new Node(1);
    head->next->next = new Node(2);
    head->next->next->next = new Node(3);
    head->next->next->next->next = new Node(3);
    head->next->next->next->next->next = new Node(4);

    cout << "Original List: ";
    printList(head);

    Solution obj;
    head = obj.removeDuplicates(head);

    cout << "After Removing Duplicates: ";
    printList(head);

    return 0;
}

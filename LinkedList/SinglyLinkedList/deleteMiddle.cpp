#include <bits/stdc++.h>
using namespace std;

class Node {
public:

    int data;  
    Node* next;     
    
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

class Solution {
public:
    // xxxxx  delete the middle node using count method xxxxxxxxxxx 

    Node* deleteMiddleBruteForce(Node* head) {

        Node* temp = head;
        
        // Variable to hold the number of nodes in the linked list
        int n = 0;
        
        // Loop to count the number of nodes in the linked list
        while (temp != NULL) {

            n++;
            temp = temp->next;
        }
        
        // Calculate the index of the before middle node
        int beforeMiddle = n / 2;
        
        // Reset the temporary node to the beginning of the linked list
        temp = head;
        
        while (temp != NULL) {
            beforeMiddle--;

            if (beforeMiddle == 0) {

                Node* middle = temp->next;
                
                // Adjust pointers to skip the middle node
                temp->next = temp->next->next;
                
                free(middle);
                
                // Exit the loop after deleting the middle node
                break;
            }
            
            // Move to the next node in the linked list
            temp = temp->next;
        }
        
        // Return the head of the modified linked list
        return head;
    }

    // xxxxxxxxxx delete the middle node using slow and fast pointer xxxxxxxxx

    Node* deleteMiddle(Node* head) {

        if (head == nullptr || head->next == nullptr) {
            delete head;
            return nullptr;
        }

        // Initialize slow pointer to head
        Node* slow = head;

        // Initialize fast pointer two steps ahead
        Node* fast = head->next->next;

        // Traverse until fast reaches end
        while (fast != nullptr && fast->next != nullptr) {
            
            slow = slow->next;
            fast = fast->next->next;
        }

        // Pointer to middle node
        Node* middle = slow->next;

        // Bypass the middle node
        slow->next = slow->next->next;

        // Delete middle node
        delete middle;

        // Return head of updated list
        return head;
    }
};

void printLL(Node* head) {
    Node* temp = head;
    
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
        cout << endl;
}


int main() {
    // Creating a sample linked list
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    
    // Display the original linked list
    cout << "Original Linked List: ";
    printLL(head);

    Solution obj;
    
    // Deleting the middle node
    head = obj.deleteMiddle(head);

    // Displaying the updated linked list
    cout << "Updated Linked List: ";
    printLL(head);

    return 0;
}

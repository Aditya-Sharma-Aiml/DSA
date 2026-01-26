#include <bits/stdc++.h>
using namespace std;


class Node {
public:
    int data;      
    Node* next;     

    // Constructor with both data and next node as parameters
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    // Constructor with only data as a parameter, sets next to nullptr
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

//xxxxxxx check if the linked list is a palindrome using stack xxxxxxx
// xxxxxxxxxxxxxxxxx [T.C.-> O(2*N) , S.C. -> O(N)] xxxxxxxxxxx

bool isPalindromeUsingStack(Node* head) {

    
    stack<int> st;

    // Initialize a temporary pointer to the head of the linked list
    Node* temp = head;

    // Traverse the linked list and push values onto the stack

    while (temp != NULL) {

        st.push(temp->data); 
        temp = temp->next;  
    }

    // Reset the temporary pointer back to the head of the linked list
    temp = head;

    // Compare values by popping from the stack and checking against linked list nodes

    while (temp != NULL) {

        if (temp->data != st.top()) {

            // If values don't match, it's not a palindrome
            return false;
        }
        st.pop();          
        temp = temp->next;  
    }

    // If all values match, it's a palindrome
    return true;
}


//xxxxxxx check if the linked list is a palindrome optimalxxxxxxx
// xxxxxxxxxxxxxxxxx [T.C.-> O(2*N) , S.C. -> O(1)] xxxxxxxxxxx

Node* reverseLinkedList(Node* head) {
    
    if (head == NULL || head->next == NULL) {
        return head;  
    }

    // Recursive step: Reverse the remaining part of the list and get the new head
    Node* newHead = reverseLinkedList(head->next);

    // Store the next node in 'front' to reverse the link
    Node* front = head->next;

    // Update the 'next' pointer of 'front' to point to the current head
    front->next = head;

    // Set the 'next' pointer of the current head to null to break the original link
    head->next = NULL;

    // Return the new head obtained from the recursion
    return newHead;
}


bool isPalindrome(Node* head) {
    
    if (head == NULL || head->next == NULL) {
        return true; 
    }

    // Initialize two pointers, slow and fast, to find the middle of the linked list
    Node* slow = head;
    Node* fast = head;

    // Traverse the linked list to find the middle using slow and fast pointers
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;      
        fast = fast->next->next;
    }

    // Reverse the second half of the linked list starting from the middle
    Node* newHead = reverseLinkedList(slow->next);

    Node* first = head; // Pointer to the first half

    Node* second = newHead; // Pointer to the reversed second half

    // Compare data values of nodes from both halves
    while (second != NULL) {

        if (first->data != second->data) {
            // If values do not match, the list is not a palindrome

            reverseLinkedList(newHead);  // Reverse the second half back to its original state
            return false;
        }

        first = first->next;  // Move the first pointer
        second = second->next; // Move the second pointer
    }

    // Reverse the second half back to its original state
    reverseLinkedList(newHead);

    // The linked list is a palindrome
    return true;
}


void printLinkedList(Node* head) {

    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " "; 
        temp = temp->next;         
    }
    cout << endl;
}


int main() {
    
    // Create a linked list with values 1, 5, 2, 5, and 1 (15251, a palindrome)
    Node* head = new Node(1);
    head->next = new Node(5);
    head->next->next = new Node(2);
    head->next->next->next = new Node(5);
    head->next->next->next->next = new Node(1);

    
    cout << "Original Linked List: ";
    printLinkedList(head);
    
    
    if (isPalindrome(head)) {
        cout << "The linked list is a palindrome." << endl;
    } else {
        cout << "The linked list is not a palindrome." << endl;
    }
    cout << "Original Linked List: ";
    printLinkedList(head);

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list node
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:

    // ======== reverse a linked list using stack =========
    // =========== [T.C.-> O(2N), S.C. -> O(N)] ==========

    ListNode* reverseListusingStack(ListNode* head) {
        // Stack to store values of nodes
        stack<int> st;

        // Temporary pointer to traverse the list
        ListNode* temp = head;

        // Traverse and push all node values to stack
        while (temp != NULL) {
            st.push(temp->val);
            temp = temp->next;
        }

        // Reset temp back to head
        temp = head;

        // Reassign values from stack in reverse order
        while (temp != NULL) {
            temp->val = st.top();
            st.pop();
            temp = temp->next;
        }

        // Return the modified head
        return head;
    }


    // ============= reverse a linked list iteratively =================
    // =========== [T.C.-> O(N), S.C. -> O(1)] =================

    ListNode* reverseListIterative(ListNode* head) {
        
        ListNode* backward = NULL;
        // ListNode* forward = NULL;

        ListNode* curr = head;

        // Traverse the list
        while (curr != NULL) {

            // Save the next node
            ListNode* forward = curr->next;

            // Reverse the current node's pointer
            curr->next = backward;

            // Move backward to current node
            backward = curr;

            // Move to the next node
            curr = forward;
        }

        // Return new head (last node becomes first)
        return backward;
    }

    // ========= Recursive function to reverse the linked list ==========
    // =========== [T.C.-> O(N), S.C. -> O(N)] ===================

    ListNode* reverseList(ListNode* head) {
        // Base case: if list is empty or has one node
        if (head == NULL || head->next == NULL)
            return head;

        // Recursively reverse the rest of the list
        ListNode* newHead = reverseList(head->next);

        // backtrack krte time:

        // Store the next node
        ListNode* front = head->next;

        // Make the next node point back to current
        front->next = head;

        // Break the current node's forward link
        head->next = NULL;

        // Return the new head of the reversed list
        return newHead;
    }
};

// Driver code
int main() {
    Solution sol;

    // Creating linked list 1 -> 2 -> 3 -> NULL
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    
    head = sol.reverseListusingStack(head);
    head = sol.reverseListIterative(head);
    head = sol.reverseList(head);

    // Printing reversed list
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }

    return 0;
}

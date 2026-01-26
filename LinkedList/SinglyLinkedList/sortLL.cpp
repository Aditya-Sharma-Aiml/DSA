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

//xxxx [T.C.-> O(NlogN), S.C. -> O(logN):recursion depth stack space] xxxxxx

class Solution {
public:

    Node* mergeTwoSortedLinkedLists(Node* list1, Node* list2) {

        Node* dummyNode = new Node(-1);

        // Temp pointer to build merged list
        Node* temp = dummyNode;

        // Traverse both lists
        while (list1 != nullptr && list2 != nullptr) {

            // Choose smaller node
            if (list1->data <= list2->data) {
                temp->next = list1;
                list1 = list1->next;

            } else {
                temp->next = list2;
                list2 = list2->next;
            }
            // Move temp pointer
            temp = temp->next;
        }

        // Attach remaining nodes
        if (list1 != nullptr) {
            temp->next = list1;
        } else {
            temp->next = list2;
        }

        // Return head of merged list
        return dummyNode->next;
    }

    Node* findMiddle(Node* head) {
        
        // If list empty or single node
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        // initialize Slow and fast pointers to reach slow at m1 soemiddle
        Node* slow = head;
        Node* fast = head->next;

        while (fast != nullptr && fast->next != nullptr) {

            slow = slow->next;
            fast = fast->next->next;
        }

        // Return middle node
        return slow;
    }

    // Function to perform merge sort
    Node* sortLL(Node* head) {

        // Base case: empty or single node
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        // Find middle node
        Node* middle = findMiddle(head);

        // Split into two halves
        Node* left = head;
        Node* right = middle->next;

        middle->next = nullptr;//break the link (divide into two left nad right)

        // Recursively sort both halves
        left = sortLL(left);
        right = sortLL(right);

        // Merge sorted halves
        return mergeTwoSortedLinkedLists(left, right);
    }
};

void printLinkedList(Node* head) {

    Node* temp = head;
    while (temp != nullptr) {

        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {

    // Create linked list: 3 -> 2 -> 5 -> 4 -> 1
    Node* head = new Node(3);
    head->next = new Node(2);
    head->next->next = new Node(5);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(1);

    cout << "Original Linked List: ";
    printLinkedList(head);

    Solution obj;

    head = obj.sortLL(head);

    cout << "Sorted Linked List: ";
    printLinkedList(head);

    return 0;
}

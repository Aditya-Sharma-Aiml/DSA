#include <bits/stdc++.h>
using namespace std;

// Node class represents a node in a linked list
class Node {
public:
    // Data stored in the node
    int data;

    // Pointer to the next node
    Node* next;

    // Constructor with both data and next node
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    // Constructor with only data
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};


class Solution {

public:
    //xxxxxxxxxxxxx length of loop using hashing xxxxxxxxxxxx
    // xxxxxxxxxxxxxxxxx [T.C.-> O(N) , S.C. -> O(N)] xxxxxxxxxxx

    int lengthOfLoopUsingHashing(Node* head) {

        // Hashmap to store visited nodes and their timer values
        unordered_map<Node*, int> visitedNodes;

        // Pointer to traverse the linked list
        Node* temp = head;

        // Timer to track visited nodes
        int timer = 0;

        // Traverse the linked list till temp reaches nullptr
        while (temp != NULL) {
            // If revisiting a node, return the difference of timer values
            if (visitedNodes.find(temp) != visitedNodes.end()) {
                // Calculate the length of the loop
                int loopLength = timer - visitedNodes[temp];

                // Return the length of the loop
                return loopLength;
            }

            // Store the current node and its timer value
            visitedNodes[temp] = timer;

            // Move to the next node
            temp = temp->next;

            // Increment the timer
            timer++;
        }

        // If traversal is completed and we reach the end of the list
        // means there is no loop
        return 0;
    }


    // xxxxxxxxxxx length of loop using Floyd's Algorithm xxxxxxxxxx
    // xxxxxxxxxxxxxxxxx [T.C.-> O(N) , S.C. -> O(1)] xxxxxxxxxxx

    int lengthOfLoop(Node* head) {

        Node* slow = head;
        Node* fast = head;

        // Loop until fast and slow meet
        while (fast != NULL && fast->next != NULL) {

       
            slow = slow->next;
            fast = fast->next->next;

            // If slow and fast meet, loop detected
            if (slow == fast) {

                // Count the length of the loop
                return countLoopLength(slow);
            }
        }

        // No loop found
        return 0;
    }

    int countLoopLength(Node* meetingPoint) {

        Node* temp = meetingPoint;

        temp = temp->next;
        int length = 1;

        // Move until we meet again
        while (temp != meetingPoint) {
            
            temp = temp->next;
            length++;
        }
        return length;
    }
};


int main() {

    // Creating a sample linked list with a loop
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);

    // Linking the nodes
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    // Creating a loop from fifth to second
    fifth->next = second;

    // Creating a Solution object
    Solution obj;

    // Getting the loop length
    int loopLength = obj.lengthOfLoop(head);

    // Printing the result
    if (loopLength > 0) {
        cout << "Length of the loop: "
             << loopLength << endl;
    } else {
        cout << "No loop found in the linked list."
             << endl;
    }

    return 0;
}

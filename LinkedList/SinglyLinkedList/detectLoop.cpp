#include <bits/stdc++.h>
using namespace std;


class Node {
public:
    // Data stored in the node
    int data;

    // Pointer to the next node
    Node* next;

    // Constructor with data and next
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
    
    //  xxxxxxxxxxx using marker visited -> Unordered_map xxxxxxxxxxxxxx
    // xxxxxxxxxxxxxxxxx [T.C.-> O(N LOG N ) , S.C. -> O(N)] xxxxxxxxxxx

    bool detectLoopUsingVisitedMarker(Node* head) {
       
        Node* temp = head;

        // Create a map to keep track of visited nodes
        unordered_map<Node*, int> nodeMap; // not data take node becoz data might be duplicate in list

        
        while (temp != nullptr) {

            // If node already exists in map, loop detected
            if (nodeMap.find(temp) != nodeMap.end()) {
                return true;
            }

            // Store the current node in the map
            nodeMap[temp] = 1;

            temp = temp->next;
        }

        // If traversal completes, no loop detected
        return false;
    }

    // xxxxxxxxxxxxx hare and tortoise method(slow and fast) xxxxxxxxxxx
    // xxxxxxxxxxxxxxxxx [T.C.-> O(N) , S.C. -> O(1)] xxxxxxxxxxx

    bool detectLoop(Node* head){

        Node* slow = head;
        Node* fast = head;

        // move kro ye dhyan me rakh ke odd and even length ki LL ho skti hai 
        while(fast != NULL && fast->next != NULL){

            slow = slow->next; // move 1 step
            fast = fast->next->next; // move two step

            // stop point agar loop paa gye to bs return kr jao
            if(slow == fast) return true;
        }

        // loop nhi paya
        return false;
    }

};

int main() {

    // Create sample linked list nodes
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);

    // Link the nodes
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    // Create a loop for testing
    fifth->next = third;

    // Create a Solution object
    Solution obj;

    // Check if loop exists
    if (obj.detectLoop(head)) {
        cout << "Loop detected in the linked list." << endl;
    } else {
        cout << "No loop detected in the linked list." << endl;
    }

    // Free allocated memory
    delete head;
    delete second;
    delete third;
    delete fourth;
    delete fifth;

    return 0;
}

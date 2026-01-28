#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int x) {
        data = x;
        prev = NULL;
        next = NULL;
    }
};

// 🔹 Remove duplicates from sorted DLL
Node* removeDuplicates(Node* head) {

    if (!head) return head;

    Node* curr = head;

    while (curr && curr->next) {

        if (curr->data == curr->next->data) {

            Node* dup = curr->next;
            curr->next = dup->next;

            if (dup->next)
                dup->next->prev = curr;

            delete dup;
        }
        else {
            curr = curr->next;
        }
    }
    return head;
}

// 🔹 Array → DLL
Node* arrayToDLL(const vector<int>& arr) {
    if (arr.empty()) return NULL;

    Node* head = new Node(arr[0]);
    Node* curr = head;

    for (int i = 1; i < arr.size(); i++) {
        Node* newNode = new Node(arr[i]);
        curr->next = newNode;
        newNode->prev = curr;
        curr = newNode;
    }
    return head;
}

// 🔹 Print DLL
void printDLL(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {

    vector<int> arr = {1, 1, 2, 3, 3, 3, 4, 5, 5};
    Node* head = arrayToDLL(arr);

    cout << "Original DLL: ";
    printDLL(head);

    head = removeDuplicates(head);

    cout << "After removing duplicates: ";
    printDLL(head);

    return 0;
}

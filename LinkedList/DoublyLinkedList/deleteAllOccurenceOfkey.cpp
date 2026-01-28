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

// 🔹 Delete all occurrences of key
Node* deleteAllOuccrence(Node* head, int key) {
    Node* temp = head;

    while (temp) {

        if (temp->data == key) {

            // agar head delete ho raha hai
            if (temp == head) {
                head = temp->next;
                if (head) head->prev = NULL;
            }

            Node* nextNode = temp->next;
            Node* prevNode = temp->prev;

            if (nextNode) nextNode->prev = prevNode;
            if (prevNode) prevNode->next = nextNode;

            free(temp);
            temp = nextNode;
        }
        else {
            temp = temp->next;
        }
    }
    return head;
}

// 🔹 Print DLL
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
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

int main() {

    vector<int> arr = {10, 4, 10, 10, 6, 10};
    int key = 10;

    Node* head = arrayToDLL(arr);

    cout << "Original DLL: ";
    printList(head);

    head = deleteAllOuccrence(head, key);

    cout << "After deleting " << key << ": ";
    printList(head);

    return 0;
}

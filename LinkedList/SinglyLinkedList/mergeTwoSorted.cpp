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


// xxxxxxxxxxxxxxxx merge two sorted linked lists using array xxxxxxxxxxxxx
// xxxxxxxx [T.C.-> O(2N) + O(NlogN) : (N=N1+N2), S.C. -> O(N)] xxxxxxxxxxx

Node* convertArrToLinkedList(vector<int>& arr){

    Node* dummyNode = new Node(-1);
    Node* temp = dummyNode;


    for(int i = 0; i < arr.size(); i++){

        temp->next = new Node(arr[i]); 
        temp = temp->next; 
    }

    return dummyNode->next; 
}

Node* mergeTwoSortedLL(Node* list1, Node* list2) {

    vector<int> arr;
    Node* temp1 = list1;
    Node* temp2 = list2;

   
    while(temp1 != NULL){

        arr.push_back(temp1->data); 
        temp1 = temp1->next; 
    }
    
    while(temp2 != NULL){
        arr.push_back(temp2->data);
        temp2 = temp2->next; 
    }
    
    sort(arr.begin(), arr.end());

    Node* head = convertArrToLinkedList(arr); 
    
    return head; 
}



//xxxxxxxxxxxxxx merge two sorted linked lists xxxxxxxxxxxxxxxxxxx
// xxxxxxxxxxxxxxxxx [T.C.-> O(N1 + N2) , S.C. -> O(1)] xxxxxxxxxxx

Node* mergeTwoSortedLinkedLists(Node* list1, Node* list2) {

    // Create a dummy node to serve as the head of the merged list
    Node* dummyNode = new Node(-1);
    Node* temp = dummyNode;

    // Traverse both lists simultaneously
    while (list1 != nullptr && list2 != nullptr) {

        // Compare elements of both lists and link the smaller node to the merged list
        if (list1->data <= list2->data) {

            temp->next = list1;
            list1 = list1->next;
        } else {

            temp->next = list2;
            list2 = list2->next;
        }
        // Move the temporary pointer to the next node
        temp = temp->next; 
    }

    // If any list still has remaining elements, append them to the merged list
    if (list1 != nullptr) {
        temp->next = list1;
    } else {
        temp->next = list2;
    }

    // Return the merged list starting from the next of the dummy node
    return dummyNode->next;
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

    Node* list1 = new Node(1);
    list1->next = new Node(3);
    list1->next->next = new Node(5);

    Node* list2 = new Node(2);
    list2->next = new Node(4);
    list2->next->next = new Node(6);

    cout << "First sorted linked list: ";
    printLinkedList(list1);

    cout << "Second sorted linked list: ";
    printLinkedList(list2);

    Node* mergedList = mergeTwoSortedLinkedLists(list1, list2);

    cout << "Merged sorted linked list: ";
    printLinkedList(mergedList);

    return 0;
}
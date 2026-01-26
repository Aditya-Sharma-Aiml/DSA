#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:

    // xxxxxxxxxxxxxxxxx [T.C.-> O(2*N) , S.C. -> O(N)] xxxxxxxxxxx
    ListNode* oddEvenListUsingArray(ListNode* head) {
        if (!head || !head->next) return head;

        vector<int>arr;
        ListNode* temp = head;

        // push odd place node->data
        while(temp != NULL && temp -> next != NULL){
            arr.push_back(temp->val);
            temp = temp -> next -> next;
        }
        // edge case if temp last node pe pahunch gya toh usko add nhi krega so check and add it 
        if(temp) arr.push_back(temp->val);

        
        // push even place node->data
        temp = head -> next;
        while(temp != NULL && temp -> next != NULL){
            arr.push_back(temp->val);
            temp = temp -> next -> next;
        }
        // edge case if temp last node pe pahunch gya toh usko add nhi krega so check and add it 
        if(temp) arr.push_back(temp->val);


        // REPLACE data
        temp = head;
        int i=0;
        while(temp != NULL){
            temp-> val = arr[i++];
            temp = temp -> next;
        }
        return head;
    }

    // xxxxxxxxxxxxxxxxx [T.C.-> O(N) , S.C. -> O(1)] xxxxxxxxxxx
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* odd = head;               // start of odd list
        ListNode* even = head->next;        // start of even list
        ListNode* evenHead = even;          // save for later

        // rearrange links until no more even next
        while (even && even->next) {

            odd->next = even->next;         // link odd to next odd
            odd = odd->next;

            even->next = odd->next;         // link even to next even
            even = even->next;
        }

        odd->next = evenHead;               // connect end of odd to start of even
        return head;
    }
};

void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Creating linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original List: ";
    printList(head);

    Solution sol;
    head = sol.oddEvenList(head);

    cout << "After Odd-Even Rearrangement: ";
    printList(head);

    return 0;
}
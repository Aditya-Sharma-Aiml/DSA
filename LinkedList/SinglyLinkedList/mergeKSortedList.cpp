#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:

    // better:

    // merge two sorted lists
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (l1 && l2) {
            if (l1->val <= l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }

        if (l1) tail->next = l1;
        if (l2) tail->next = l2;

        return dummy.next;
    }

    // merge k sorted lists using sequential merge
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return NULL;

        ListNode* head = lists[0];

        for (int i = 1; i < lists.size(); i++) {
            head = mergeTwoLists(head, lists[i]);
        }

        return head;
    }

    // optimal:

    ListNode* mergeKListsUsingPriorityQueue(vector<ListNode*>& lists) {
        if (lists.size() == 0) return NULL;

        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        // define min heap
        priority_queue<pair<int,ListNode*>, vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>>pq;

        //insert all list in heap
        for(int i=0; i<lists.size(); i++){

            if(lists[i]){
                pq.push({lists[i]->val, lists[i]});
            }
        }

        // merging start untill pq is not empty
        while(!pq.empty()){

            auto it = pq.top(); // min heap se min (top) ko nikalo aor pop kr do
            pq.pop();

            // agar top ka next node exist krta hai toh usko heap me fir daal do
            if(it.second->next){
                pq.push({it.second->next->val,it.second->next});
            }

            // top ke node ko link kro apne merging process me
            temp->next = it.second;
            temp = temp -> next;
        }
        return dummy -> next;

    }


};

// helper to print list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Creating lists
    // L1: 1 -> 4 -> 5
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(5);

    // L2: 1 -> 3 -> 4
    ListNode* l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);

    // L3: 2 -> 6
    ListNode* l3 = new ListNode(2);
    l3->next = new ListNode(6);

    vector<ListNode*> lists = {l1, l2, l3};

    Solution sol;
    ListNode* result = sol.mergeKListsUsingPriorityQueue(lists);

    cout << "Merged List: ";
    printList(result);

    return 0;
}

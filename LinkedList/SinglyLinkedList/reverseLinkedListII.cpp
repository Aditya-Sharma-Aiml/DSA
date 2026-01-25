
#include <bits/stdc++.h>
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if(head == NULL || head -> next == NULL) return head;

        ListNode* dummy = new ListNode(0);
        dummy -> next = head; // imp

       // suru me  leftPrev dummy ko point krega
        //baad me int left node ke phle ko point krega
        // jisase agar 1 -> any node reverse krna ho toh crash na ho
        ListNode* leftPrev = dummy; 

        ListNode* curr = head;

        for(int i=0; i<left-1; i++){
            leftPrev = leftPrev->next; // ye left marker ke phle ruk jayega 
            curr = curr->next;
        }
        
        // hamare pass do chizen hai 1st leftPrev and 2nd subHead
        // we need marker jhn se mene reversing start ki hai
        ListNode*  subHead = curr;

        ListNode* backward = NULL;

        // apply reverse
        for(int i=0; i<=right-left ; i++){
            
            ListNode* forward = curr -> next;
            curr -> next = backward;
            backward = curr;
            curr = forward;

        }

        // end of the day connect broken piece with the help of humne joh do marker rakhe hai
        leftPrev -> next = backward;
        subHead -> next = curr;

        return dummy->next;
    }
};

int main() {

    // Create linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Before : ";
    ListNode* temp = head;
    while (temp != NULL) {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";

    Solution sol;
    int left = 2, right = 4;

    head = sol.reverseBetween(head, left, right);

    cout << "After  : ";
    temp = head;
    while (temp != NULL) {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";

    return 0;
}

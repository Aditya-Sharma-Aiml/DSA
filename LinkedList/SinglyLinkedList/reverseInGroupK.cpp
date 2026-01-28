
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 // without recursion
class Solution1 {
    private:
    ListNode* getKthNode(ListNode* temp, int k){
        k -= 1;
        while(k>0 && temp){
            k--;
            temp = temp->next;
        }
        return temp;
    }
    ListNode* reverse(ListNode* temp){
        if(!temp || !temp->next) return temp;

        ListNode* backward = NULL;
        ListNode* curr = temp;
        while(curr){
            ListNode* forward = curr->next;
            curr->next = backward;
            backward = curr;
            curr = forward;
        }
        return backward;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode* temp = head;
        ListNode* prevLast = NULL; // point to prev of next node

        while(temp){

            //1) phle kth node pao
            ListNode* kthNode = getKthNode(temp, k);
            //jb kth node NULL ho mtlb remaining node < k ho
            if(kthNode == NULL){
                //tb bs link kro no reverse
                // but jb prev NULL na ho kyonki null ka next nullptr error d
                if(prevLast) prevLast->next = temp; 
                break;
            }
            
             // store next of kth for furthor revrese tracking
            ListNode* nextNode = kthNode->next;

            kthNode->next = NULL; //break link to reverse
            reverse(temp);

            // agar phla reverse hai toh head ko update krna hoga
            if(temp == head) head = kthNode;
            else{
                prevLast -> next = kthNode;
            }
            prevLast = temp;
            temp = nextNode;

        }
        return head;

    }
};
// with recursion
class Solution2 {
public:

    //reverse exactly k nodes
    ListNode* reverseK(ListNode* head, int k) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;

        while (curr && k--) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev; // new head after reverse
    }

    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* curr = head;
        int count = 0;

        // Step 1: check if k nodes exist
        while (curr && count < k) {
            curr = curr->next;
            count++;
        }

        if (count < k) return head;  // not enough nodes

        // Step 2: reverse first k nodes using helper
        ListNode* newHead = reverseK(head, k);

        // Step 3: recursive call for remaining list
        head->next = reverseKGroup(curr, k);

        return newHead;
    }
};


// 🔹 array → linked list converter
ListNode* arrayToList(const vector<int>& arr) {
    if (arr.empty()) return nullptr;

    ListNode* head = new ListNode(arr[0]);
    ListNode* curr = head;

    for (int i = 1; i < arr.size(); i++) {
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }
    return head;
}

// 🔹 print linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Solution1 sol1;
    Solution2 sol2;

    vector<int> arr = {1, 2, 3, 4, 5,6,7,8,9,10,11};
    int k = 3;

    ListNode* head = arrayToList(arr);

    cout << "Original List: ";
    printList(head);

    head = sol2.reverseKGroup(head, k);

    cout << "After Reverse " << k << " Group: ";
    printList(head);

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

struct node {

    int data;
    node* next;
    node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
public:

    // xxxxxxxxxxx check presence of intersection brute force xxxxxxxxxx
    // xxxxxxxxxxxxx [T.C.-> O(N1 + N2) , S.C. -> O(N1)] xxxxxxxxxxxxxxxxxx
    
    
    node* intersectionPresent_bruteforce(node* head1, node* head2) {
        
        unordered_set<node*> st;  // Set to store visited nodes from the first list
        while (head1 != NULL) {

            st.insert(head1);  // Insert nodes of the first list into the set
            head1 = head1->next;
        }
        while (head2 != NULL) {

            if (st.find(head2) != st.end()) return head2;  // If node is found in set, it's the intersection point
            head2 = head2->next;
        }
        return NULL;  // Return NULL if no intersection is found
    }
    
    
    // optimal 1:
    // xxxxxxxxxxxxx [T.C.-> O(2* (N1 + N2)) , S.C. -> O(N1)] xxxxxxxxxxxxxx
    
    //get the difference in lengths of two linked lists 
    int getDifference(node* head1, node* head2) {
        int len1 = 0, len2 = 0;
        while (head1 != NULL || head2 != NULL) {
            if (head1 != NULL) {
                ++len1;
                head1 = head1->next;
            }
            if (head2 != NULL) {
                ++len2;
                head2 = head2->next;
            }
        }
        return len1 - len2;  // If negative, length of list2 > length of list1, else vice-versa
    }
    
    //xxxxxxxxxx check presence of intersection xxxxxxxxxxxxxx
    
    node* intersectionPresent_length(node* head1, node* head2) {
        int diff = getDifference(head1, head2);
        
        if (diff < 0) 
        while (diff++ != 0) head2 = head2->next;
        else 
        while (diff-- != 0) head1 = head1->next;
        
        // Traverse both lists and compare node by node
        while (head1 != NULL) {

            if (head1 == head2) return head1;  // Intersection point found
            head2 = head2->next;
            head1 = head1->next;
        }
        return head1;  // Return NULL if no intersection
    }
    
    
    // optimal 2:
    // xxxxxxxxxxxxx [T.C.-> O(2* (N1 + N2)) , S.C. -> O(N1)] xxxxxxxxxxxxxx
    
    node* getIntersectionNode(node* headA, node* headB) {
        
        // Agar kisi bhi linked list ka head NULL hai,
        // to intersection possible nahi hai
        if(headA == nullptr || headB == nullptr)
            return nullptr;

        // t1 pointer list A se traverse karega
        // t2 pointer list B se traverse karega
        node *t1 = headA;
        node *t2 = headB;

        // Loop tab tak chalega jab tak
        // dono pointers same node par nahi aa jaate
        while(t1 != t2){

            // Dono pointers ko ek-ek step aage badhao
            t1 = t1->next;
            t2 = t2->next;

            // Agar dono same node par aa gaye,
            // wahi intersection point hoga
            if(t1 == t2)
                return t1;

            // Agar t1 list A ke end par pahunch gaya,
            // to usse list B ke head par bhej do
            if(t1 == nullptr)
                t1 = headB;

            // Agar t2 list B ke end par pahunch gaya,
            // to usse list A ke head par bhej do
            if(t2 == nullptr)
                t2 = headA;
        }

        // Yahan do cases ho sakte hain:
        // 1) Intersection node mil gaya
        // 2) Dono pointers NULL par mil gaye (no intersection)
        return t1;
    }

    void printList(node* head) {

        while (head != NULL) {
            cout << head->data << " ";
            head = head->next;
        }
        cout << endl;
    }
};

int main() {

    node* common = new node(8);
    common->next = new node(10);

    node* head1 = new node(3);
    head1->next = new node(6);
    head1->next->next = new node(9);
    head1->next->next->next = common;

    node* head2 = new node(4);
    head2->next = common;

    Solution sol;

    node* ans1 = sol.intersectionPresent_bruteforce(head1, head2);
    node* ans2 = sol.intersectionPresent_length(head1, head2);
    node* ans3 = sol.getIntersectionNode(head1, head2);

    cout << "Bruteforce Intersection: " << (ans1 ? ans1->data : -1) << endl;
    cout << "Length Difference Intersection: " << (ans2 ? ans2->data : -1) << endl;
    cout << "Two Pointer Intersection: " << (ans3 ? ans3->data : -1) << endl;

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n²), as each element is popped and inserted at the bottom (O(n) per element).

// Space Complexity: O(n), as only the recursion stack is used.

// Function to insert an element at the bottom of the stack
void insertAtBottom(stack<int> &st, int val) {
    // If stack is empty, push the value
    if (st.empty()) {
        st.push(val);
        return;
    }

    // Pop the top element
    int topVal = st.top();
    st.pop();

    // Recurse for the rest of the stack -> recrn leap of failt
    insertAtBottom(st, val);

    // Push the popped element back
    st.push(topVal);
}

// Function to reverse the stack
void reverseStack(stack<int> &st) {
    // Base case: If stack is empty, return
    if (st.empty()) return;

    // Pop the top element
    int topVal = st.top();
    st.pop();

    // Recurse for the rest of the stack -> recrn leap of failt
    reverseStack(st); 

    // Insert the popped element at the bottom
    insertAtBottom(st, topVal);
}

int main() {
    // Create a sample stack
    stack<int> st;
    st.push(4);
    st.push(1);
    st.push(3);
    st.push(2);

    // Reverse the stack
    reverseStack(st);

    // Print the reversed stack
    cout << "Reversed Stack: ";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;

    return 0;
}
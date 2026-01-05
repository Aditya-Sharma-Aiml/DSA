#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(n^2), where n is the number of elements in the stack.

// Space Complexity: O(n), due to the recursion stack.

void sortedInsert(stack<int>&st , int num){

    //base case-> 1). agar top < num : insert kr do  OR 2). stack empty ho tb toh dal hi do num ko
    if(st.empty() || ( !st.empty() && st.top() < num)){
        st.push(num);
        return ;
    }

    int top = st.top();
    st.pop();

    // leaap of faith on rucursn 
    sortedInsert(st,num);

    // wapas aane ke baad top (popped element) ko bhi to dalna hoga na 
    st.push(top);

}
void sortStack(stack<int> &st){

    // base case -> jese hi stack khali ho return kr jao aor fir uske baad wapas jate time sorted way me insert krte jana -> sortedInsert()
    if (st.empty()) return ;

    int top = st.top();
    st.pop();

    // trust on recrn
    sortStack(st);

    //wapas jaate time sorted way me insert krna
    sortedInsert(st,top);
}

int main(){

    int n;
    cin >> n;
    stack<int>st;

    for(int i=0 ;i<n ; i++){
        int num ;
        cin >> num;
        st.push(num);
    }
    sortStack(st);

    // Print the sorted stack
    cout << "Sorted stack (descending order): ";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;

}

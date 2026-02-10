#include <bits/stdc++.h>
using namespace std;

// Class to implement Minimum Stack using pair  space : (2*N) , time O(1)

class MinStack1 {
private:
    // Initialize a stack
    stack <pair<int,int>> st;
    
public:
    
    // Empty Constructor
    MinStack1() {
    }
    
    // Method to push a value in stack
    void push(int value) {
        
        // If stack is empty
        if(st.empty()) {
            
            // Push current value as minimum
            st.push( {value, value} );
            return;
        }
        
        // Update the current minimum 
        int mini = min(getMin(), value);
        
        // Add the pair to the stack
        st.push({value, mini});
    }
    
    // Method to pop a value from stack
    void pop() {
        // Using in-built pop method
        st.pop(); 
    }
    
    // Method to get the top of stack
    int top() {
        // Return the top value
        return st.top().first;
    }
    
    // Method to get the minimum in stack
    int getMin() {
        // Return the minimum
        return st.top().second;
    }
};

// Class to implement Minimum Stack : Space O(N) , time : O(1)

class MinStack2 {
private:
    // Initialize a stack
    stack <int> st;
    // To store the minimum value 
    int mini;
    
public:
    
    // Empty Constructor
    MinStack2() {
    }
    
    // Method to push a value in stack
    void push(int value) {
        
        // If stack is empty
        if(st.empty()) {
            //Update the minimum value
            mini = value;
            
            // Push current value as minimum
            st.push( value );
            return;
        }
        
        // If the value is greater than the minimum
        if(value > mini) {
            st.push(value);
        }
        else {
            // Add the modified value to stack
            st.push(2 * value - mini);
            // Update the minimum
            mini = value;
        }
    }
    
    // Method to pop a value from stack
    void pop() {
        // Base case
        if(st.empty()) return;
        
        // Get the top
        int x = st.top();
        st.pop(); // Pop operation
        
        // If the modified value was added to stack
        if(x < mini) {
            // Update the minimum
            mini = 2 * mini - x;
        }
    }
    
    // Method to get the top of stack
    int top() {
        // Base case
        if(st.empty()) return -1;
        
        // Get the top
        int x = st.top();
        
        // Returnn top if minimum is less than the top
        if(mini < x) return x;
        
        //Otherwise return mini
        return mini;
    }
    
    // Method to get the minimum in stack
    int getMin() {
        // Return the minimum
        return mini;
    }
};

int main() {
    MinStack2 s;
    
    // Function calls
    s.push(-2);
    s.push(0);
    s.push(-3);
    cout << s.getMin() << " ";
    s.pop();
    cout << s.top() << " ";
    s.pop();
    cout << s.getMin();
    
    return 0;
}
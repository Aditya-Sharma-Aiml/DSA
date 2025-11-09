#include<iostream>
#include<stack>
#include<string>

using namespace std;

// Approach -1 : using stack
//Time : O(N)
//Space : O(N)
int maxDepthStack(string s){

    stack<char>st;
    int depth = 0;

    for(char ch : s){
        // ( -> push to stack
        if(ch == '(') st.push(ch);
        // ) -> pop from stack
        else if(ch == ')') st.pop();

        // maxdepth maximum size of stack
        depth = max(depth, (int)st.size());// (int) -> because stack.sie() return size in "size_t" datatype 

    }
    return depth;

}
// Approach -1 : open bracket  depth counter
//Time : O(N)
//Space : O(1)
int maxDepth(string s){

    int openBrackets = 0;
    int depth = 0;

    for(char ch : s){
        // ( -> we are going deeper 
        if(ch == '(') openBrackets++;
        // ) -> we are getting out
        else if(ch == ')') openBrackets--;

        // maxdepth maximum of openBrackets 
        depth = max(depth, openBrackets); 

    }
    return depth;
}
int main(){
    string s = "(1+(2*3)+((8)/4))+1";
    
    // cin >> s;
    int maximumDepth = maxDepth(s);
    cout << maximumDepth;
}

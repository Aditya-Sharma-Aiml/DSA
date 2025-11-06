#include<iostream>
#include<string>
#include<stack>
using namespace std;

//Approach - 1 : stack based
// time : o(N)
// space : O(N)

string removeOuterMost(string s){

    stack<char>st;
    string ans = "";

    for(char c : s){

        if (c == '('){

            // "(" -> first check stack is empty or not then push and decide add to ans or skip

            if (!st.empty()) ans += '(';
            st.push('(');
        }
        else if( c == ')'){

            // ")" -> first pop then check stack is empty or not, and then decide add to ans or skip

            st.pop();
            if(!st.empty()) ans += ')';

        }
    }
    return ans;
}

// Approach - 2
// Time : O(N)
// space : O(1)

string removeOuterMostParentheses(string s){
    int open = 0;
    string ans = "";

    for(char ch : s){

        //'(' -> check the 'open' counter before open++ 
        if(ch == '('){
            if(open > 0) ans += '(';
            open++;
        }
        else if ( ch == ')'){
            //')' -> check the 'open' counter after the open--;
            open--;
            if(open > 0) ans += ')';
        }

        // xxxxx manage multiple line xxxxx

        // if (ch==')') open--;
        // if(open > 0) ans.push_back(ch);
        // if(ch == '(') open++;
    }
    return ans;
}
int main(){
    string s;
    cin >> s;
    cout << removeOuterMost(s) << endl;
    cout << removeOuterMostParentheses(s);
}
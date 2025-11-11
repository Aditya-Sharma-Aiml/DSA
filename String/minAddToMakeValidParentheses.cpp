
#include <bits/stdc++.h>
using namespace std;

// Time : O(N)

int minAddToMakeValid(string s) {
    // s = "()))(("
    int open = 0;
    int close = 0;
    for(int i=0 ; i<s.length() ; i++){

        if(s[i] == '(') {
            open++;
        }
        else{  // ) -> Aaya hai

            // open > 0: mean  "(" -> bacha hai, isko ")" balance krne ke liye
            if(open > 0){  
                open--;
            }
            //open <= 0 : mean "(" -> nhi bacha, isko ")" balance ke liye toh mtlb close jada ho gya
            else{   
                close++;
            }
        }
    }
    // need = close ")" ke liye -> "(" open  + open "(" ke liye -> close ")"
    return open + close;
}
int main(){
    string s = "()))((";
    cout << "min move to make VPS :" << minAddToMakeValid(s);
}
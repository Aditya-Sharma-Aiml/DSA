#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(n * 2^n), there can be n iterations, with string length of upto 2^n characters.

// Space Complexity: O(2^n), Final string length can reach upto 2^n

string countAndSay(int n) {
        
    if(n == 1) return "1";
    string result = "";
    //create say string which will give (n-1)th sequence 
    // using recursion call 
    string say = countAndSay(n-1);

    // processing of generating count and say sequence
    for(int i=0 ; i<say.length() ; i++){

        //pick a char
        char ch = say[i];
        int countSame = 1;

        //go in say string untill we didn't get diff char
        while(i < say.length()-1 && say[i] == say[i+1]){
            countSame++;
            i++;
        }
        // add to result "no.of times of a char" + "char";
        result += to_string(countSame) + string(1, ch);
    }
    return result;
}
int main(){
    int n;
    cin >> n;
    string nthSequence = countAndSay(n);
    cout << nthSequence;
}
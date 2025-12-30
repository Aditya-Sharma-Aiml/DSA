#include <bits/stdc++.h>
using namespace std;

//xxxxxxxxxxxxxxxxxxx BruteForce xxxxxxxxxxxxxx

// Time Complexity: O(2^(2n) * n) due to the generation and validation of all 2^(2n) sequences.

// Space Complexity: O(n) space required per sequence.

// Check if a string has valid parentheses
bool isValid(string s) {
    int balance = 0;
    for (char c : s) {
        if (c == '(') balance++;
        else balance--;
        if (balance < 0) return false;
    }
    return balance == 0;
}

void generateAll(string curr, int n, vector<string>& res) {
    if (curr.length() == 2 * n) {
        if (isValid(curr)) res.push_back(curr);
        return;
    }
    generateAll(curr + '(', n, res);
    generateAll(curr + ')', n, res);
}

vector<string> generateParenthesis_bruteForce(int n) {
    vector<string> res;
    generateAll("", n, res);
    return res;
}

//xxxxxxxxxxxxxxxxxxx Optimal xxxxxxxxxxxxxx

// Time Complexity: O(2^n) (Catalan number): C(n) = (2n)! / (n!(n+1)!) is the number of valid sequences.
// Each sequence takes O(n) to build.
// So, total complexity: O(C(n) × n)

// Space Complexity: O(n) recursion depth.
// O(C(n) × n) to store results.

void backtrack(string curr, int open, int close, int n, vector<string>& res) {
    if (curr.length() == 2 * n) {
        res.push_back(curr);
        return;
    }
    // choice 1 : generate next ( -> if open < n (bcoz open == n == close)
    if (open < n) backtrack(curr + '(', open+1, close, n, res);
    //choice 2 : generate next ) -> if open > close : to mke valid parentheses
    if (close < open) backtrack(curr + ')', open, close+1, n, res);
}

vector<string> generateParenthesis(int n) {
    vector<string> res;
    backtrack("", 0, 0, n, res);
    return res;
}


int main() {
    int n ;
    cin >> n;
    // vector<string> result = generateParenthesis_bruteForce(n);
    vector<string> result = generateParenthesis(n);
    for (string s : result) cout << s << endl;
    return 0;
}
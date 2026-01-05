#include <bits/stdc++.h>
using namespace std;

// xxxxx return all binary strings of length n that do not contain consecutive 1s. Return the result in lexicographically increasing order. xxxxxxxx

// Time Complexity: O(2^n), since each position has 2 choices.

// Space Complexity: O(n) per recursive path (due to call stack)

void generate(int n, string curr, vector<string>& result) {
    // Base case: if length is n, add to result
    if (curr.length() == n) {
        result.push_back(curr);
        return;
    }

    //Always try adding '0'
    generate(n, curr + "0", result); // left call recursion for 0

    // Add '1' only if previous char is not '1'
    if (curr.empty() || curr.back() != '1') {
        generate(n, curr + "1", result); // right call recursion for 1
    }
}

int main() {
    // Input length n
    int n = 3;

    vector<string> result;

    // Start recursion with empty string
    generate(n, "", result);

    // Print results
    for (string& s : result) {
        cout << s << " ";
    }
    cout << endl;
    return 0;
}
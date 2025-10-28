#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int squareSum(int n) {
        int sum = 0;
        while (n > 0) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }
        return sum;
    }
    // time and space : Log(N)
    bool isHappy_hashing(int n){
        set<int> seen;
        while (n != 1 && !seen.count(n)) {
            seen.insert(n);
            n = squareSum(n);
        }
        return n == 1;
    }
    bool isHappy(int n) {
        int slow = n, fast = n;
        do {
            slow = squareSum(slow);
            fast = squareSum(squareSum(fast));
        } while (slow != fast);
        return slow == 1;
    }
};

int main() {
    Solution obj;
    int n;
    cout << "Enter a number: ";
    cin >> n;

    if (obj.isHappy(n))
        cout << n << " is a Happy Number " << endl;
    else
        cout << n << " is NOT a Happy Number " << endl;

    return 0;
}

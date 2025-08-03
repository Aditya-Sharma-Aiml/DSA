#include <bits/stdc++.h>
using namespace std;

// use half adder
int sumOfTwoNum(int x, int y) {
    while (y != 0) {
        int sum = x ^ y;         // XOR: sum without carry
        int carry = (x & y) << 1; // AND then shift: carry
        x = sum;
        y = carry;
    }
    return x;
}

int main() {
    int a = 5, b = 4;
    cout << "Sum: " << sumOfTwoNum(a, b) << endl;
    return 0;
}

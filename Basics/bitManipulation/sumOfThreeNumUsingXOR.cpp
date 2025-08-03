#include <bits/stdc++.h>
using namespace std;

// Half Adder: Adds two numbers without using '+' operator
int sumOfTwoNum(int x, int y) {
    while (y != 0) {
        int sum = x ^ y;          // XOR gives partial sum
        int carry = (x & y) << 1; // AND gives carry, shift left
        x = sum;
        y = carry;
    }
    return x;
}

// Full Adder using two Half Adders
int sumOfThreeNum(int a, int b, int c) {
    int firstSum = sumOfTwoNum(a, b);   // Half Adder 1
    int finalSum = sumOfTwoNum(firstSum, c); // Half Adder 2
    return finalSum;
}

int main() {
    int x = 2, y = 5, z = 9;
    int sum = sumOfThreeNum(x, y, z);
    cout << "Sum: " << sum << endl;
    return 0;
}

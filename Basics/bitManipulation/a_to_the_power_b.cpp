#include <iostream>
#include <cmath>
using namespace std;

// Bitwise multiplication function
int multiplyBitwise(int a, int b) {
    int result = 0;
    int times = abs(b);
    int addend = abs(a);

    while (times > 0) {
        if (times & 1) { // if last bit is 1
            result += addend;
        }
        addend <<= 1; // multiply by 2
        times >>= 1;  // divide by 2
    }

    // Handle sign of result
    if ((a < 0 && b > 0) || (a > 0 && b < 0)) {
        return -result;
    }
    return result;
}

// Bitwise exponentiation function
int powerBitwise(int base, int exponent) {
    int result = 1;
    int absExp = abs(exponent);

    for (int i = 0; i < absExp; i++) {
        result = multiplyBitwise(result, base);
    }

    // If exponent is negative, return integer division of 1/result
    if (exponent < 0) {
        return 0; // No fractional support for int
    }
    return result;
}

int main() {
    cout << powerBitwise(2, 5) << endl; // 32
    cout << powerBitwise(3, 4) << endl; // 81
    cout << powerBitwise(-2, 3) << endl; // -8
}

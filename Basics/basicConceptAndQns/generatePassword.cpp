#include <bits/stdc++.h>
using namespace std;

// Check if all non-zero frequencies are the same
bool isFreqSame(int freq[]) {
    int expectedFreq = 0;
    for (int i = 0; i < 10; i++) {
        if (freq[i] != 0) {
            expectedFreq = freq[i];
            break;
        }
    }
    for (int i = 0; i < 10; i++) {
        if (freq[i] != 0 && freq[i] != expectedFreq)
            return false;
    }
    return true;
}

// Check if a number is stable
bool isStable(int num) {
    int freq[10] = {0};
    while (num > 0) {
        int digit = num % 10;
        freq[digit]++;
        num /= 10;
    }
    return isFreqSame(freq);
}

// Generate password
int generatePassword(vector<int>& arr) {
    int st = 0, unst = 0;
    for (int num : arr) {
        if (isStable(num))
            st += num;
        else
            unst += num;
    }
    return abs(st - unst);
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int password = generatePassword(arr);
    cout << "Password: " << password << endl;
    return 0;
}

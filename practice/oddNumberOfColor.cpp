#include<bits/stdc++.h>
using namespace std;

// Frequency count method
char oddColor(vector<char>& color) {

    unordered_map<char, int> freq;

    for(char ch : color) {
        freq[ch]++;
    }

    for(auto it : freq) {
        if(it.second & 1) {
            return it.first;
        }
    }

    return '\0';
}

// HashSet method
char findOddColor(vector<char>& color) {

    unordered_set<char> st;

    for(char ch : color) {

        if(st.find(ch) == st.end()) {
            st.insert(ch);
        }
        else {
            st.erase(ch);
        }
    }

    if(st.empty()) {
        return '\0';
    }

    return *(st.begin());
}

int main() {

    int n;
    cin >> n;

    vector<char> color(n);

    for(int i = 0; i < n; i++) {
        cin >> color[i];
    }

    char ans1 = oddColor(color);
    char ans2 = findOddColor(color);

    if(ans1 != '\0')
        cout << ans1 << endl;
    else
        cout << "all are even" << endl;

    if(ans2 != '\0')
        cout << ans2 << endl;
    else
        cout << "all are even" << endl;

    return 0;
}

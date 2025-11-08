#include<bits/stdc++.h>
using namespace std;

bool checkIfPangram(string sentence) {
    
    vector<int>freq(26,0);
    
    for(char ch : sentence){
        freq[ch -'a']++;
    }
    // we can alse use for loop 
    bool allPresent = all_of(begin(freq),
                                end(freq),
                                [](int element){
                                    return element > 0;
                                });

    return allPresent;
}
int main(){
    string sentence;
    getline(cin , sentence);
    cout << checkIfPangram(sentence);
}
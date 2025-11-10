#include <bits/stdc++.h>
using namespace std;

// time : O(N)

class Solution {
  public:
    int countSubstrWith_AtMost_Kdistinct(string s, int k){
        
        vector<int>mp(26,0);
        
        int left = 0, right = 0;
        int distinct = 0;
        
        long long ans= 0;
        
        // Sliding Window
        while(right < s.length()){
            
            // increase freq of char
            mp[s[right]-'a']++;
            
            // jesi hi koi new char aaye distinct ko ek badha do
            if( mp[s[right]-'a'] == 1) distinct++;
            
            while(distinct > k){
                // frequecy decrease kro left ki then 
                // window size ko reduce kro
                mp[s[left]-'a']--;
                // agar freq zero ho gyi left ki toh distinct ek kum kr do
                if(mp[s[left]-'a'] <= 0) distinct--;
                
                left++;
            }
            // number of substring
            ans += right - left + 1;
            // increase window size
            right++;
        }
        return ans;
    }
    int countSubstr(string& s, int k) {

        if (k == 0) return 0; // no substring can have 0 distinct chars
        // atmost(k) - atmost(k-1) = exactly(k)
        return countSubstrWith_AtMost_Kdistinct(s,k)
                - countSubstrWith_AtMost_Kdistinct(s,k-1);
        
    }
};

int main() {
    string s;
    int k;
    cin >> s; // abaaca
    cin >> k; // 2
    Solution sol;

    cout << "Count of substrings with exactly " << k 
         << " distinct characters = " << sol.countSubstr(s, k) << endl; // 10

    return 0;
}
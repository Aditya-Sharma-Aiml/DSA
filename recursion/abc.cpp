#include<bits/stdc++.h>
using namespace std;
void backtrack(int idx, vector<char>&s, vector<vector<char>>&ans){

    if(idx >= s.size()) {
        ans.push_back(s);
        return ;
    }
    

    char temp = s[idx];

    s[idx] = '1';
    backtrack(idx+1, s, ans);
    
    s[idx] = temp;
    backtrack(idx+1, s, ans);

}
int main(){

    int n;
    cin >> n;
    vector<char>s(n);

    vector<vector<char>>ans;

    for(int i=0; i<n ; i++){
        cin >> s[i];
    }

    backtrack(0, s, ans);

    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[0].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}
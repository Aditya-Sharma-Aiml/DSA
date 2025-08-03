#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.emplace_back(3);
    for(auto x:v){
        cout<<x << " " <<endl;
    }
    vector<pair<int,int>> vec;
    vec.push_back({1,2});
    vec.emplace_back(1,2);
    for(auto x:vec){
        cout << x.first << " " <<x.second<< endl; 
    }

    
}
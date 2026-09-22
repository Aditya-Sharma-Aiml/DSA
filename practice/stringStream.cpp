# include <iostream>
# include <sstream>
#include<bits/stdc++.h>
using namespace std;

int main(){

    // xxxxxxxxxxxxxxxx method1: "1 2 3 4 5 6" xxxxxxxxxxxxxxxxxxxx
    string s;
    getline(cin, s);

    stringstream ss(s);
    int num;

    vector<int>arr;
    while(ss >> num){
        arr.push_back(num);
    }

    for(int num : arr){
        cout << num << " ";
    }
    cout << endl;
    // cout << typeid(s).name() << endl;
    // cout << typeid(ss).name();


    // xxxxxxxxxxxxxxxxxx METHOD2 : "1,2,3,4,5,6,7" xxxxxxxxxxxxxxxxxx

    string str;
    getline(cin , str);

    stringstream obj_ss(str);
    string temp;

    vector<int> nums;
    while(getline(obj_ss, temp, ',')){
        // int num = stoi(temp);
        // nums.push_back(num);
        nums.push_back(stoi(temp));
    }
    for(int num : nums){
        cout << num << " ";
    }

}
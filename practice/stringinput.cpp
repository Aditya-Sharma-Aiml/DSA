#include<bits/stdc++.h>
using namespace std;
int main(){

    int n;
    cin >> n;

    //cin.ignore() input buffer me bacha hua newline (\n) ya extra characters remove karta hai taaki next getline() sahi input le sake.
    cin.ignore();

    string s;
    getline(cin, s);
    cout << n << " " << s;

    }
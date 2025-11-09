#include<bits/stdc++.h>
using namespace std;

//Time: O(1)
//Space: O(1)


string intToRoman(int num) {

    // total values = 13
    static vector<int>values{1000, 900, 500, 400,
                                100, 90, 50, 40, 10, 9, 5, 4, 1};
    // total symbol = 13
    static vector<string>symbol{"M", "CM", "D", "CD",
                                "C", "XC", "L", "XL", "X",  "IX", "V", "IV", "I"};
    string ans = "";
        
    // because roman write as in decreasing order so we start dividing by large number
    for(int i=0 ; i<13 ; i++){

        if( num == 0) break;

        //how many times a symbol will be add 
        //(num / value of the coresponding symbol)
        int times = num / values[i];

        while(times--){
            ans += symbol[i];
        }

        // num become remaining num = num % value of the coresponding symbol
        num = num % values[i];
    }
    return ans;
}
int main(){
    int num; 
    cin >> num; //3749
    string s = intToRoman(num);
    cout << s; //MMMDCCXLIX
}
#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;

// Approach - 1
// Time : O(nlogn)

// both strings are same bs suffeled hai toh dono ko sort krke check kr lo same hai ya nhi
bool CheckAnagrams(string str1, string str2)
{
  // Case 1: when both of the strings have different lengths
    if (str1.length() != str2.length())
        return false;
    
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());
    
    // Case 2: check if every character of str1 and str2 matches with each other
    for (int i = 0; i < str1.length(); i++)
    {
        if (str1[i] != str2[i])
        return false;
    }
    return true;
}

// Approach - 2
// Time : O(N)
// match the freq of letters in each string

bool isAnagram(string s, string t) {
        
        if(s.length() != t.length()) return false;

        // count frequency of chars
        vector<int>freq(26,0); // because all are small letters
        // increase  freq
        for(char &ch : s){
            freq[ch-'a']++;
        }
        // decrease freq
        for(char &ch : t){
            freq[ch-'a']--;
        }

        // check all are zero in freq all not
        // if all zero mean both string have same freq of letters
        // we can use for loop or STL to check
        bool allZeros = all_of(begin(freq),
                                end(freq),
                                [](int element){
                                    return element == 0;
                                });
        return allZeros;
    }

int main()
{
  string Str1 = "INTEGER";
  string Str2 = "TEGERNI";
  if(isAnagram(Str1, Str2))
  cout << "True" << endl;
  else
  cout<<"False"<<endl;
  return 0;
}
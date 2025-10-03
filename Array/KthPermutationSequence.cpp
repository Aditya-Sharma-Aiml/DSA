#include <bits/stdc++.h>

using namespace std;



class Solution {
  public:

    // Brute Force:
    // Time complexity: O(N! * N) +O(N! Log N!)
    // space : O(N)

    //function to generate all possible permutations of a string
    void permutationHelper(string & s, int index, vector < string > & res) {

      if (index == s.size()) {

        res.push_back(s);
        return;
      }

      for (int i = index; i < s.size(); i++) {

        swap(s[i], s[index]); 
        permutationHelper(s, index + 1, res);
        swap(s[i], s[index]);

      }
    }

  string getPermutation(int n, int k) {

    string s;
    vector < string > res;

    //create string
    for (int i = 1; i <= n; i++) {
      s.push_back(i + '0');
    }

    permutationHelper(s, 0, res);

    //sort the generated permutations
    sort(res.begin(), res.end());

    //make k 0-based indexed to point to kth sequence
    auto it = res.begin() + (k - 1);
    return *it;
  }


    // Optimal:

    // Time Complexity: O(N) * O(N) = O(N^2)
    //Space : O(N)

  string getKthPermutation(int n, int k) {

      int fact = 1;

      vector < int > numbers;

      for (int i = 1; i < n; i++) { // store 1->n numbers

        fact = fact * i; // calculate fact of (n-1) to find block index of kth exist and for next depth k;
        numbers.push_back(i);

      }

      numbers.push_back(n); 

      string ans = "";

      k = k - 1; // kth -> exist on (k-1)th index

      while (true) {

        ans = ans + to_string(numbers[k / fact]); //add to ans (k/fact) index num and erase that num
        numbers.erase(numbers.begin() + k / fact);

        if (numbers.size() == 0) { // if no numbers yet then break
          break;
        }

        k = k % fact; // next depth of k  
        fact = fact / numbers.size(); // fact of new n-1
      }
      return ans;
    }
};

int main() {
  int n ,k;
  cin >>n>>k;
  Solution obj;
  string ans = obj.getKthPermutation(n, k);
  cout << "The Kth permutation sequence is " << ans << endl;

  return 0;
}
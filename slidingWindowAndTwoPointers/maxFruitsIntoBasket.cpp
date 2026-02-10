#include <bits/stdc++.h>
using namespace std;

class SolutionBruteForce { // Time -> O(N^2)
public:
    // Function to calculate maximum fruits collected  
    // with at most two distinct types from any start point 
    int totalFruit(vector<int>& fruits) {

        // Variable to store the maximum fruits collected
        int maxFruits = 0;

        // Loop over each possible starting point
        for (int start = 0; start < fruits.size(); ++start) {

            // Create a map to store the count of fruit types
            unordered_map<int, int> basket;

            // Initialize current count
            int currentCount = 0;

            // Traverse from current start to the end
            for (int end = start; end < fruits.size(); ++end) {

                // Add current fruit to the basket
                basket[fruits[end]]++;

                // If basket has more than 2 types, break
                if (basket.size() > 2) {
                    break;
                }

                // Increase current fruit count
                currentCount++;
            }

            // Update maximum fruits collected
            maxFruits = max(maxFruits, currentCount);
        }

        // Return the result
        return maxFruits;
    }
};

class SolutionOptimal1 {// Time -> O(N)
public:
    // Function to find the maximum number of fruits we can collect with at most two fruit types
    int totalFruit(vector<int>& fruits) {
        // Hash map to store frequency of each fruit in the current window
        unordered_map<int, int> basket;
        
        // Variable to store the maximum length of valid window
        int maxFruits = 0;
        
        // Left pointer of the sliding window
        int left = 0;

        // Traverse the fruits array using right pointer
        for (int right = 0; right < fruits.size(); right++) {
            // Include the current fruit in the basket
            basket[fruits[right]]++;

            // Shrink the window if more than 2 types of fruits exist
            while (basket.size() > 2) { // use "if" to reduce time of while 

                // Decrease count of fruit at left pointer
                basket[fruits[left]]--;

                // If count becomes zero, remove it from map
                if (basket[fruits[left]] == 0) {
                    basket.erase(fruits[left]);
                }

                // Move the left pointer to shrink the window
                left++;
            }

            // Update the maximum window length found so far
            maxFruits = max(maxFruits, right - left + 1);
        }

        // Return the maximum fruits we can collect in a valid window
        return maxFruits;
    }
};
class SolutionOptimal2 {
public:

    // Function to find the maximum number of fruits we can collect
    // with at most two types of fruits in the baskets.
    int totalFruit(vector<int>& fruits) {
        
        // Variable to store the maximum number of fruits collected
        int maxlen = 0;
        
        // Variables to track the last two fruit types and their counts
        int lastfruit = -1, secondlastfruit = -1;
        
        // Count of current window size and the last fruit streak
        int currcount = 0, lastfruitstreak = 0;

        // Traverse through each fruit in the array
        for (int fruit : fruits) {
            
            // If current fruit is same as last or second last, increase window
            if (fruit == lastfruit || fruit == secondlastfruit) {
                currcount++;
            } else {
                // Reset window size to size of last fruit streak + 1 (current fruit)
                currcount = lastfruitstreak + 1;
            }

            // Update streak count
            if (fruit == lastfruit) {
                lastfruitstreak++;

            } else {

                lastfruitstreak = 1;
                secondlastfruit = lastfruit;
                lastfruit = fruit;
            }

            // Update the maximum length
            maxlen = max(maxlen, currcount);
        }

        return maxlen;
    }
};


// Driver code
int main() {

    SolutionOptimal2 obj;
    vector<int> fruits = {1, 2, 1};
    
    cout << obj.totalFruit(fruits) << endl; // Output: 3
    return 0;
}

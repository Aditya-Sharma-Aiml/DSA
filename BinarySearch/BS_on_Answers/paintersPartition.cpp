#include <bits/stdc++.h>
using namespace std;

//  xxxxxx Same As BOOK ALLOCATION xxxxxx

// Time Complexity: O(N * log(sum(arr[])-max(arr[])+1))

int countPainters(vector<int> &boards, int time) {

    int n = boards.size();

    int painters = 1;
    long long boardsPainter = 0;

    for (int i = 0; i < n; i++) {

        if (boardsPainter + boards[i] <= time) {
            //allocate board to current painter
            boardsPainter += boards[i];
        }
        else {
            //allocate board to next painter
            painters++;
            boardsPainter = boards[i];
        }
    }
    return painters;
}

int findLargestMinDistance(vector<int> &boards, int k) {

    int low = *max_element(boards.begin(), boards.end());
    int high = accumulate(boards.begin(), boards.end(), 0);
    //Apply binary search:
    while (low <= high) {

        int mid = (low + high) / 2; // mid -> time

        int painters = countPainters(boards, mid);

        if (painters > k) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return low;
}
int main()
{
    vector<int> boards = {10, 20, 30, 40};
    int k = 2;
    int ans = findLargestMinDistance(boards, k);
    cout << "The answer is: " << ans << "\n";
    return 0;
}
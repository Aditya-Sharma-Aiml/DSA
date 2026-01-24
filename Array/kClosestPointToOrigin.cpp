#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    void calculateDistance(vector<vector<int>>& points,
                           map<int, vector<pair<int,int>>>& disPath){

        for (int i = 0; i < points.size(); i++) {
            int x = points[i][0];
            int y = points[i][1];

            int dist = x*x + y*y;   // NO sqrt
            disPath[dist].push_back({x, y});
        }
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        vector<vector<int>> ans;
        map<int, vector<pair<int,int>>> disPath;

        calculateDistance(points, disPath);

        for (auto &it : disPath) {
            for (auto &p : it.second) {
                if (k == 0) return ans;
                ans.push_back({p.first, p.second});
                k--;
            }
        }
        return ans;
    }
};

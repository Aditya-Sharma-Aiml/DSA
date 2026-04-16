#include <bits/stdc++.h>
using namespace std;

class StockSpanner {
    stack<pair<int,int>> st;
    int idx = -1;
public:
    StockSpanner() {        
        idx = -1;
        while(!st.empty()) st.pop();
    }
    
    int next(int price) {
        idx += 1;
        while(!st.empty() && st.top().first <= price) st.pop();
        int ans = idx - (st.empty() ? -1 : st.top().second);
        st.push({price, idx});
        return ans;
    }
};

int main() {
    StockSpanner obj;
    
    vector<int> prices = {100, 80, 60, 70, 60, 75, 85};

    for (int price : prices) {
        cout << obj.next(price) << " ";
    }

    return 0;
}
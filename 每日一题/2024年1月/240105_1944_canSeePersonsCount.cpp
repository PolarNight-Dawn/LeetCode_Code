#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;
//
// Created by polarnight on 24-1-5, 下午3:01.
//

class Solution {
public:
    vector<int> canSeePersonsCount(vector<int> &heights) {
        int n = heights.size();
        vector<int> ans(n, 0);

        stack<int> sta;
        for (int i = n - 1; i >= 0; i--) {
            while (!sta.empty() && heights[i] >= sta.top()) {
                sta.pop();
                ans[i]++;
            }
            if (!sta.empty()) ans[i]++;
            sta.push(heights[i]);
        }
        return ans;
    }
};

int main2401051944() {
    vector<int> heights = {4, 3, 2, 1};

    Solution sol;
    auto result = sol.canSeePersonsCount(heights);

    for (auto &res: result) {
        cout << res << " ";
    }
    cout << endl;

    return 0;
}

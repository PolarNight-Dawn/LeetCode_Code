#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;
//
// Created by polarnight on 23-12-21, 下午2:47.
//

class Solution {
public:
    //! \TLE 时间复杂度为O(n^2)
    // long long maximumSumOfHeights(vector<int>& maxHeights) {
    //     int n = maxHeights.size();
    //     vector<long long> dp(n, 0);
    //
    //     for (int i = 0; i < n; i++) {
    //         long long height_sum = maxHeights[i], temp = maxHeights[i];
    //         for (int j = i; j < n - 1; j++) {
    //             if (temp <= maxHeights[j + 1]) height_sum += temp;
    //             else {
    //                 height_sum += maxHeights[j + 1];
    //                 temp = maxHeights[j + 1];
    //             }
    //         }
    //         dp[i] = height_sum;
    //     }
    //
    //     for (int i = n - 1; i >= 0; i--) {
    //         long long height_sum = maxHeights[i], temp = maxHeights[i];
    //         for (int j = i; j > 0; j--) {
    //             if (temp <= maxHeights[j - 1]) height_sum += temp;
    //             else {
    //                 height_sum += maxHeights[j - 1];
    //                 temp = maxHeights[j - 1];
    //             }
    //         }
    //         if (i != n - 1) dp[i + 1] += height_sum;
    //     }
    //
    //     return *max_element(dp.begin(), dp.end());
    // }

    long long maximumSumOfHeights(vector<int>& maxHeights) {
        int n = maxHeights.size();
        vector<long long> suf(n + 1);
        stack<int> sta;
        sta.push(n);
        long long height_sum = 0;
        for (int i = n - 1; i >= 0; i--) {
            int curr = maxHeights[i];
            while (sta.size() > 1 && curr <= maxHeights[sta.top()]) {
                int j = sta.top();
                sta.pop();
                height_sum -= (long long) maxHeights[j] * (sta.top() - j);
            }
            height_sum += (long long) curr * (sta.top() - i);
            suf[i] = height_sum;
            sta.push(i);
        }


    }
};

int main2312212866() {
    vector<int> maxHeughts = {3,2,5,5,2,3};

    Solution sol;
    cout << sol.maximumSumOfHeights(maxHeughts);

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

//
// Created by polarnight on 23-12-8, 下午2:38.
//

class Solution {
public:
    // 深度优先算法 + 记忆化搜索
    // 时间复杂度O(n^2) TLE
    // long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
    //     int len = rides.size();
    //     sort(rides.begin(), rides.end(), [](vector<int> &a, vector<int> &b) {
    //         return a[0] < b[0];
    //     });
    //
    //     unordered_map<int, unordered_map<int, long long>> memo;
    //
    //     function<long long(int, int)> DFS = [&](int end, int cnt) -> long long {
    //         if (cnt == len) return 0;
    //
    //         if (memo.find(end) != memo.end() && memo[end].find(cnt) != memo[end].end())
    //             return memo[end][cnt];
    //
    //         long long result = 0;
    //         for (int i = cnt; i < len; i++) {
    //             if (end <= rides[i][0]) {
    //                 long long ans = rides[i][2] + rides[i][1] - rides[i][0];
    //                 ans += DFS(rides[i][1], i);
    //                 result = max(result, ans);
    //             }
    //         }
    //         memo[end][cnt] = result;
    //         return result;
    //     };
    //     return DFS(0, 0);
    // }

    long long maxTaxiEarnings(int n, vector<vector<int>> &rides) {
        int len = rides.size();
        sort(rides.begin(), rides.end(), [](vector<int> &a, vector<int> &b) {
            return a[1] < b[1];
        });

        vector<long long> dp(len + 1);
        for (int i = 0; i < len; i++) {
            int j = upper_bound(rides.begin(), rides.begin() + i, rides[i][0], [](int x, const vector<int> &r) -> bool {
                return x < r[1];
            }) - rides.begin();
            dp[i + 1] = max(dp[i], dp[j] + rides[i][1] - rides[i][0] + rides[i][2]);
        }
        return dp[len];
    }
};

int main2008() {
    int n = 20;
    vector<vector<int>> rides = {{1,  6,  1},
                                 {3,  10, 2},
                                 {10, 12, 3},
                                 {11, 12, 2},
                                 {12, 15, 2},
                                 {13, 18, 1}};

    Solution sol;
    cout << sol.maxTaxiEarnings(n, rides);

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//
// Created by polarnight on 23-12-31, 下午3:29.
//

class Solution {
public:
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
        function<bool(int)> Check = [&](int mid) -> bool {
            long long money = INT64_MAX;
            for (int i = 0; i < composition.size(); i++) {
                long long tmp = 0;
                for (int j = 0; j < composition[0].size(); j++) {
                    long long temp = composition[i][j] * static_cast<long long>(mid);
                    if (temp > stock[j]) tmp += (temp - stock[j]) * cost[j];
                }
                money = min(money, tmp);
            }
            return money > budget;
        };

        int left = 1, right = 2e8;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (Check(mid)) right = mid - 1;
            else left = mid + 1;
        }
        return right;
    }
};

int main2861() {
    int n = 1, k = 7, budget = 48;
    vector<vector<int>> composition = {{1}, {5}, {9}, {6}, {4}, {2}, {4}};
    vector<int> stock = {6}, cost = {1};

    Solution sol;
    cout << sol.maxNumberOfAlloys(n, k, budget, composition, stock, cost);

    return 0;
}
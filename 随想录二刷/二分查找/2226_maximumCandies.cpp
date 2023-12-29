#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//
// Created by polarnight on 23-12-24, 下午3:59.
//

class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        function<bool(int)> Check = [&](int i) -> bool {
            long long ans = 0;
            for (auto &candy : candies) ans += candy / i;
            return ans >= k;
        };

        int max_val = *max_element(candies.begin(), candies.end());
        int left = 1, right = max_val + 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (Check(mid)) left = mid + 1;
            else right = mid - 1;
        }
        return right;
    }
};

int main2226() {
    vector<int> candies = {5,8,6};
    int k = 3;

    Solution sol;
    cout << sol.maximumCandies(candies, k);

    return 0;
}
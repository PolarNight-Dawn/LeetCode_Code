#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//
// Created by polarnight on 23-12-26, 下午4:28.
//

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        function<bool(int)> Check = [&](int mid) -> bool {
            int sum = 0, day = 1;
            for (int i = 0; i < weights.size(); i++) {
                if (mid < weights[i]) return false;
                else sum += weights[i];
                if (sum == mid) {
                    if (i == weights.size() - 1) break;
                    day += 1, sum = 0;
                } else if (sum > mid) {
                    day += 1, sum = weights[i];
                }
            }
            return day <= days;
        };

        int left = 1, right = 500 * days;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (Check(mid)) right = mid - 1;
            else left = mid + 1;
        }
        return left;
    }
};

int main1011() {
    vector<int> weights = {1,2,3,1,1};
    int days = 4;

    Solution sol;
    cout << sol.shipWithinDays(weights, days);

    return 0;
}

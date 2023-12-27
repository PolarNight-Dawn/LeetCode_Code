#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//
// Created by polarnight on 23-12-27, 下午3:12.
//

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        function<bool(long long)> Check = [&](long long mid) -> bool {
            long long hour = 0;
            for (auto &pile : piles) {
                hour += (pile - 1) / mid + 1;
            }
            return hour > h;
        };

        long long left = 1, right = 1000000000000000000;

        while (left <= right) {
            long long mid = left + (right - left) / 2;
            if (Check(mid)) left = mid + 1;
            else right = mid - 1;
        }
        return left;
    }
};

int main875() {
    vector<int> piles = {3,6,7,11};
    int h = 8;

    Solution sol;
    cout << sol.minEatingSpeed(piles, h);

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//
// Created by polarnight on 23-12-29, 下午3:28.
//

class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        function<bool(int)> Check = [&](int mid) -> bool {
            int num_m = 0, num_k = 0;
            for (int i = 0; i < n; i++) {
                if (mid < bloomDay[i]) {
                    num_m += num_k / k;
                    num_k = 0;
                } else {
                    num_k++;
                    if (i == n - 1) num_m += num_k / k;
                }
            }
            return num_m >= m;
        };

        int left = 1, right = 1e9;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (Check(mid)) right = mid - 1;
            else left = mid + 1;
        }
        return left > 1e9 ? -1 : left;
    }
};

int main1482() {
    vector<int> bloomDay = {1,10,3,10,2};
    int m = 3, k = 1;

    Solution sol;
    cout << sol.minDays(bloomDay, m, k);

    return 0;
}
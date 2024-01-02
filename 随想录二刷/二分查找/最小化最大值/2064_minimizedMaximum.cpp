#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//
// Created by polarnight on 24-1-1, 下午4:40.
//

class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int left = 1, right = *max_element(quantities.begin(), quantities.end());

        function<bool(int)> Check = [&](int mid) -> bool {
            int count = 0;
            for (auto &quantity : quantities)
                count += (quantity - 1) / mid + 1;
            return count >= n;
        };

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (Check(mid)) left = mid + 1;
            else right = mid - 1;
        }
        return right;
    }
};

int main2064() {
    int n = 6;
    vector<int> quantities = {11,6};

    Solution sol;
    cout << sol.minimizedMaximum(n, quantities);

    return 0;
}
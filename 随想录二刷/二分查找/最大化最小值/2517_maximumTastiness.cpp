#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//
// Created by polarnight on 24-1-27, 下午6:41.
//

class Solution {
public:
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(), price.end());
        int left = 1, right = price.back() - price[0];

        function<bool(int)> Check = [&](int mid) -> bool {
            int count = 1, pre = price[0];
            for (int i = 1; i < price.size(); i++) {
                if (price[i] - pre >= mid) count++, pre = price[i];
            }
            return count < k;
        };

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (Check(mid)) right = mid - 1;
            else left = mid + 1;
        }
        return right;
    }
};

int main2517() {
    vector<int> price = {13,5,1,8,21,2};
    int k = 3;

    Solution sol;
    cout << sol.maximumTastiness(price, k);

    return 0;
}
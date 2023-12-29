#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//
// Created by polarnight on 23-12-29, 下午2:51.
//

class Solution {
public:
    //! \时间复杂度 O(n log n)
    // int buyChoco(vector<int>& prices, int money) {
    //     sort(prices.begin(), prices.end());
    //
    //     int ans = money;
    //     for (int i = 0; i < 2; i++)
    //         ans -= prices[i];
    //
    //     return ans >= 0 ? ans : money;
    // }

    //! \时间复杂度 O(n)
    int buyChoco(vector<int>& prices, int money) {
        int first_min = INT32_MAX, second_min = INT32_MAX;

        for (auto &price : prices) {
            if (price < first_min) {
                second_min = first_min;
                first_min = price;
            } else if (price < second_min) {
                second_min = price;
            }
        }
        return money >= first_min + second_min ? money - first_min - second_min : money;
    }
};

int main2312291706() {
    vector<int> prices = {1,2,2};
    int money = 3;

    Solution sol;
    cout << sol.buyChoco(prices, money);

    return 0;
}
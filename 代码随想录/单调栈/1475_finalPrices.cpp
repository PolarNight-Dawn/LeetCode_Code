#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;
//
// Created by polarnight on 23-12-13, 下午4:29.
//

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        stack<int> sta;
        vector<int> answers(prices);

        for (int i = 0; i < n; i++) {
            while (!sta.empty() && prices[sta.top()] >= prices[i]) {
                answers[sta.top()] = prices[sta.top()] - prices[i];
                sta.pop();
            }
            sta.push(i);
        }
        return answers;
    }
};

int main1475() {
    vector<int> prices = {8,4,6,2,3};

    Solution sol;
    auto results = sol.finalPrices(prices);

    for (auto &result : results) {
        cout << result << " ";
    }
    cout << endl;

    return 0;
}
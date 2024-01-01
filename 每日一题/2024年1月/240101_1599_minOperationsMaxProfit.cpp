#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
//
// Created by polarnight on 24-1-1, 下午2:34.
//

class Solution {
public:
    int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost) {

    }
};

int main() {
    vector<int> customers = {0,0,0,0,0,50};
    int boardingCost = 100, runningCost = 1;

    Solution sol;
    cout << sol.minOperationsMaxProfit(customers, boardingCost, runningCost);

    return 0;
}
#include <iostream>
#include <vector>

//
// Created by polarnight on 23-10-18, 下午4:35.
//

class Solution {
public:
    // 模拟 TLE
    // int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost) {
    //     int len = gas.size();
    //     for (int i = 0; i < len; i++) {
    //         if (gas[i] < cost[i]) continue;
    //         int sum = gas[i], index = (i + 1) % len;
    //         while (index != i) {
    //             sum = sum - cost[(index - 1 + len) % len] + gas[index];
    //             if (sum < cost[index]) break;
    //             index = (index + 1) % len;
    //         }
    //         if (index == i) return i;
    //     }
    //     return -1;
    // }

    // 贪心
    int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost) {
        int curSum = 0;
        int totalSum = 0;
        int start = 0;
        for (int i = 0; i < gas.size(); i++) {
            curSum += gas[i] - cost[i];
            totalSum += gas[i] - cost[i];
            if (curSum < 0) {
                start = i + 1;
                curSum = 0;
            }
        }
        if (totalSum < 0) return -1;
        return start;
    }
};

int main() {
    std::vector<int> gas = {5,8,2,8};
    std::vector<int> cost = {6,5,6,6};

    Solution sol;
    std::cout << sol.canCompleteCircuit(gas, cost);

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

//
// Created by polarnight on 24-2-28, 下午8:21.
//

class Solution {
public:
    int minIncrements(int n, vector<int> &cost) {
        int sup = 0;

        for (int i = n - 2; i >= 1; i -= 2) {
            sup += abs(cost[i] - cost[i + 1]);
            cost[i / 2] += max(cost[i], cost[i + 1]);
        }
        return sup;
    }
};

int main() {
    int n = 15;
    vector<int> cost = {764, 1460, 2664, 764, 2725, 4556, 5305, 8829, 5064, 5929, 7660, 6321, 4830, 7055, 3761};

    Solution sol;
    cout << sol.minIncrements(n, cost);

    return 0;
}
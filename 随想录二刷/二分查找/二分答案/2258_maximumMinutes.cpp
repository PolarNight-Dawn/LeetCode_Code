#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//
// Created by polarnight on 24-1-1, 下午4:09.
//

class Solution {
public:
    int maximumMinutes(vector<vector<int>> &grid) {

    }
};

int main2258() {
    vector<vector<int>> grid = {{0, 2, 0, 0, 0, 0, 0},
                                {0, 0, 0, 2, 2, 1, 0},
                                {0, 2, 0, 0, 1, 2, 0},
                                {0, 0, 2, 2, 2, 0, 2},
                                {0, 0, 0, 0, 0, 0, 0}};

    Solution sol;
    cout << sol.maximumMinutes(grid);

    return 0;
}
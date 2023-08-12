#include <iostream>
#include <vector>
#include <algorithm>

//
// Created by polarnight on 23-8-12.
//

class Solution {
public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        if (target < matrix[0][0] || target > matrix[m - 1][n - 1]) return false;

        for (int i = 0; i < m; i++) {
            if (target > matrix[i][n - 1]) continue;
            if (std::find(matrix[i].begin(), matrix[i].end(), target) != matrix[i].end()) return true;
        }

        return false;
    }
};

int main74() {
    std::vector<std::vector<int>> matrix = {{1}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    int target = 1;

    Solution sol;
    std::cout << sol.searchMatrix(matrix, target);

    return 0;
}
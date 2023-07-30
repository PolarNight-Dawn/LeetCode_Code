#include <iostream>
#include <vector>

//
// Created by polarnight on 23-7-30.
//

class Solution {
public:
    void circle(std::vector<std::vector<int>>& matrix, std::vector<int> &res, int x1, int y1, int x2, int y2) {
        if (x2 < x1 || y2 < y1) return;
        if (x1 == x2) {
            for (int i = y1; i <= y2; i++) res.push_back(matrix[x1][i]);
            return;
        }

        if (y1 == y2) {
            for (int j = x1; j <= x2; j++) res.push_back(matrix[j][y1]);
            return;
        }

        for (int i = y1; i < y2; i++) res.push_back(matrix[x1][i]);
        for (int j = x1; j < x2; j++) res.push_back(matrix[j][y2]);
        for (int i = y2 ; i > y1; i--) res.push_back(matrix[x2][i]);
        for (int j = x2; j > x1; j--) res.push_back(matrix[j][y1]);

        circle(matrix, res, x1 + 1, y1 + 1, x2 - 1, y2 - 1);
    }

    std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
        std::vector<int> res;
        int m = matrix.size();
        int n = matrix[0].size();

        circle(matrix, res, 0, 0, m - 1, n - 1);

        return  res;
    }
};

int main() {
    std::vector<std::vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    std::vector<int> res;

    Solution sol;
   res = sol.spiralOrder(matrix);

   for (auto &vec : res) {
       std::cout << vec << " ";
   }

   return 0;
}
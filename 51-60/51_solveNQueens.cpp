#include <iostream>
#include <vector>
#include <algorithm>

//
// Created by polarnight on 23-7-27.
//

class Solution {
public:
    bool isValid(std::vector<int> &row, std::vector<int> &col, std::vector<int> &bias1,
                 std::vector<int> &bias2, int i, int newRow) {
        if (std::find(row.begin(), row.end(), newRow) != row.end()) return false;
        if (std::find(col.begin(), col.end(), i) != col.end())return false;
        if (std::find(bias1.begin(), bias1.end(), newRow - i) != bias1.end())return false;
        if (std::find(bias2.begin(), bias2.end(), i + newRow) != bias2.end()) return false;

        return true;
    }

    void backTracing(std::vector<std::vector<std::string>> &res, std::vector<int> row,
                     std::vector<int> col, std::vector<int> bias1, std::vector<int> bias2,
                     std::vector<std::string> tmp, int n, int newRow) {
        if (newRow == n) {
            res.push_back(tmp);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (isValid(row, col, bias1, bias2, i, newRow)) {
                tmp[newRow][i] = 'Q';
                row.push_back(newRow), col.push_back(i), bias1.push_back(newRow - i), bias2.push_back(i + newRow);
                backTracing(res, row, col, bias1, bias2, tmp, n, newRow + 1);
                row.pop_back(), col.pop_back(), bias1.pop_back(), bias2.pop_back();
                tmp[newRow][i] = '.';
            }
        }
    }

    std::vector<std::vector<std::string>> solveNQueens(int n) {
        std::vector<std::vector<std::string>> res;
        std::vector<int> row, col, bias1, bias2;
        std::vector<std::string> tmp(n, std::string(n, '.'));

        backTracing(res, row, col, bias1, bias2, tmp, n, 0);

        return res;
    }
};

int main() {
    int n = 4;
    std::vector<std::vector<std::string>> res;

    Solution sol;
    res = sol.solveNQueens(n);

    for (auto &tmp: res) {
        for (auto &vec: tmp) {
            std::cout << vec << " ";
        }
        std::cout << std::endl;
    }
}
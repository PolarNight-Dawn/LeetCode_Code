#include <iostream>
#include <vector>

//
// Created by polarnight on 23-8-2.
//

class Solution {
public:
    void
    circle02(std::vector<int> &vec, std::vector<std::vector<int>> &res, int x1, int y1, int x2, int y2, int cnt) {
        if (x2 < x1 || y2 < y1) return;
        if (x1 == x2) {
            for (int i = y1; i <= y2; i++) res[i][x1] = vec[cnt++];
            return;
        }

        if (y1 == y2) {
            for (int j = x1; j <= x2; j++) res[y1][j] = vec[cnt++];
            return;
        }

        for (int i = y1; i < y2; i++) res[x1][i] = vec[cnt++];
        for (int j = x1; j < x2; j++) res[j][y2] = vec[cnt++];
        for (int i = y2; i > y1; i--) res[x2][i] = vec[cnt++];
        for (int j = x2; j > x1; j--) res[j][y1] = vec[cnt++];

        circle02(vec, res, x1 + 1, y1 + 1, x2 - 1, y2 - 1, cnt);
    }

    std::vector<std::vector<int>> generateMatrix(int n) {
        std::vector<std::vector<int>> res(n, std::vector<int>(n, 0));
        std::vector<int> vec;

        for (int i = 1; i <= n * n; i++) {
            vec.push_back(i);
        }

        circle02(vec, res, 0, 0, n - 1, n - 1, 0);

        return res;
    }
};

int main59() {
    std::vector<std::vector<int>> res;
    int n = 3;

    Solution sol;
    res = sol.generateMatrix(n);

    for (auto &vec: res) {
        for (auto &tmp: vec) {
            std::cout << tmp << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
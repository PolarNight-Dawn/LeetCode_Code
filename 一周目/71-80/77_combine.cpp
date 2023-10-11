#include <iostream>
#include <vector>
#include <algorithm>

//
// Created by polarnight on 23-8-13.
//

class Solution {
public:
    void BackTracing77(std::vector<std::vector<int>> &res, std::vector<int> &tmp, int n, int k, int start) {
        if (k == 0) {
            res.push_back(tmp);
            return;
        }

        for (int i = start; i <= n; i++) {
            if (std::find(tmp.begin(), tmp.end(), i) == tmp.end()) {
                tmp.push_back(i);
                BackTracing77(res, tmp, n, k - 1, i);
                tmp.pop_back();
            }
        }
    }

    std::vector<std::vector<int>> combine(int n, int k) {
        std::vector<std::vector<int>> res;
        std::vector<int> tmp;

        BackTracing77(res, tmp, n, k, 1);

        return res;
    }
};

int main77() {
    int n = 1;
    int k = 1;
    std::vector<std::vector<int>> res;

    Solution sol;
    res = sol.combine(n, k);

    for (auto &tmp : res) {
        for (auto &vec : tmp) {
            std::cout << vec << " ";
        }
        std::cout << std::endl;
    }
}
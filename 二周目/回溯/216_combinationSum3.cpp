#include <iostream>
#include <vector>

//
// Created by polarnight on 23-10-10, 下午3:39.
//

class Solution {
public:
    void backTracing02(std::vector<std::vector<int>> &res, std::vector<int>& tmp, int start, int k, int n) {
        if (k == 0) {
            if (n == 0) res.push_back(tmp);
            return;
        }

        for (int i = start; i <= 9; i++) {
            tmp.push_back(i);
            backTracing02(res, tmp, i + 1,k - 1, n - i);
            tmp.pop_back();
        }
    }

    std::vector<std::vector<int>> combinationSum3(int k, int n) {
        std::vector<std::vector<int>> res;
        std::vector<int> tmp;

        backTracing02(res, tmp, 1, k, n);

        return res;
    }
};

int main() {
    int k = 3;
    int n = 7;

    Solution sol;
    std::vector<std::vector<int>> res = sol.combinationSum3(k, n);

    for (auto &tmp : res) {
        for (auto &vec : tmp) {
            std::cout << vec << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
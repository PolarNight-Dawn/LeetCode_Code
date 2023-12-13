#include <iostream>
#include <vector>
#include <algorithm>

//
// Created by polarnight on 23-7-16.
//

class Solution {
public:
    void dfs2(std::vector<std::vector<int>> &res, std::vector<int> &candidates, std::vector<int> &temp,
              std::vector<int> &used, int target, int start, int sum) {
        if (sum == target) {
            res.push_back(temp);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            if (i > 0 && used[i - 1] == 0 && candidates[i] == candidates[i - 1]) continue;
            sum += candidates[i];
            used[i] = 1;
            temp.push_back(candidates[i]);
            if (sum <= target) {
                int newStart = i + 1;
                dfs2(res, candidates, temp, used, target, newStart, sum);
            }
            sum -= candidates[i];
            temp.pop_back();
            used[i] = 0;
        }
    }

    std::vector<std::vector<int>> combinationSum2(std::vector<int> &candidates, int target) {
        std::vector<std::vector<int>> res;
        std::vector<int> temp;
        std::vector<int> used(candidates.size(), 0);

        sort(candidates.begin(), candidates.end());
        dfs2(res, candidates, temp, used, target, 0, 0);
        return res;
    }
};

int main40() {
    std::vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;

    Solution sol;
    std::vector<std::vector<int>> res;
    res = sol.combinationSum2(candidates, target);

    for (int i = 0; i < res.size(); ++i) {
        for (int j = 0; j < res[i].size(); ++j) {
            std::cout << res[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
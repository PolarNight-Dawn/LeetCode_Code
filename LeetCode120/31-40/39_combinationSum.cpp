#include <iostream>
#include <vector>

//
// Created by polarnight on 23-7-15.
//

class Solution {
public:
    void dfs(std::vector<std::vector<int>>& res, std::vector<int>& candidates, std::vector<int>& temp,
             int target, int start, int sum) {
        if (sum == target) {
            res.push_back(temp);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            sum += candidates[i];
            temp.push_back(candidates[i]);
            if (sum <= target) {
                dfs(res,candidates, temp, target, i, sum);
                sum -= candidates[i];
                temp.pop_back();
            } else {
                sum -= candidates[i];
                temp.pop_back();
            }
        }
    }

    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        std::vector<std::vector<int>> res;
        std::vector<int> temp;
        dfs(res, candidates, temp, target, 0, 0);
        return res;
    }
};

int main39() {
    std::vector<int> candidates = {2,3,6,7};
    int target = 7;

    Solution sol;
    std::vector<std::vector<int>> res;
    res = sol.combinationSum(candidates, target);

    for (int i = 0; i < res.size(); ++i) {
        for (int j = 0; j < res[i].size() ; ++j) {
            std::cout << res[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
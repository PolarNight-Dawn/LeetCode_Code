#include <iostream>
#include <vector>
#include <algorithm>

//
// Created by polarnight on 23-10-19, 下午3:17.
//

class Solution {
public:
    int candy(std::vector<int>& ratings) {
        std::vector<int> res(ratings.size(), 1);
        for (int i = ratings.size() - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) res[i] = res[i + 1] + 1;
        }

        for (int i = 1; i < ratings.size(); i++) {
            if (ratings[i] > ratings[i - 1]) res[i] = std::max(res[i - 1] + 1, res[i]);
            else res[i] = std::max(1, res[i]);
        }

        int ans = 0;
        for (auto &vec : res) ans += vec;
        return ans;
    }
};

int main() {
    std::vector<int> ratings = {1,3,2,2,1};

    Solution sol;
    std::cout << sol.candy(ratings);

    return 0;
}
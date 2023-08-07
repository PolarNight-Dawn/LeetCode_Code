#include <iostream>
#include <vector>

//
// Created by polarnight on 23-8-7.
//

class Solution {
public:
    std::vector<int> plusOne(std::vector<int>& digits) {
        std::vector<int> res(digits.size() + 1, 0);

        int cnt = 0;
        for (int i = digits.size() - 1; i >= 0; i--) {
            if (i == digits.size() - 1) digits[i]++;
            if (cnt != 0) {
                res[i + 1] = ++digits[i];
                cnt = 0;
            } else {
                res[i + 1] = digits[i];
            }
            if (digits[i] >= 10) {
                res[i + 1] = digits[i] % 10;
                cnt++;
                if (i == 0) res[0] += 1;
            }
        }

        if (res[0] == 0) res.erase(res.begin());
        return res;
    }
};

int main66() {
    std::vector<int> digits = {4, 3, 9};
    std::vector<int> res;

    Solution sol;
    res = sol.plusOne(digits);

    for (auto &vec : res) {
        std::cout << vec << " ";
    }

    return 0;
}
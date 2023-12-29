#include <iostream>
#include <vector>

//
// Created by polarnight on 23-8-7.
//

class Solution {
public:
    std::vector<int> plusOne(std::vector<int>& digits) {
        std::vector<int> res(digits.size() + 1, 0);

        int carry = 0;
        for (int i = digits.size() - 1; i >= 0; i--) {
            if (i == digits.size() - 1) digits[i]++;
            int val = digits[i] + carry;
            carry = val / 10;
            res[i + 1] = val % 10;
        }

        if (carry == 1 && !res.empty()) res[0] = 1;
        else res.erase(res.begin());
        return res;
    }
};

int main66() {
    std::vector<int> digits = {9};
    std::vector<int> res;

    Solution sol;
    res = sol.plusOne(digits);

    for (auto &vec : res) {
        std::cout << vec << " ";
    }

    return 0;
}
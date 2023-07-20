#include <iostream>
#include <vector>

//
// Created by polarnight on 23-7-19.
//

class Solution {
public:
    std::string multiply(std::string num1, std::string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        std::vector<int> mul1, mul2;
        int len1 = num1.size();
        int len2 = num2.size();
        std::vector<int> res(len1 + len2, 0);

        for (int i = len1 -1; i >= 0; i--) mul1.push_back(num1[i] - '0');
        for (int i = len2 -1; i >= 0; i--) mul2.push_back(num2[i] - '0');

        for (int i = 0; i < len1; i++) {
            for (int j = 0; j < len2; j++) {
                res[i + j] += mul1[i] * mul2[j];
            }
        }

        for (int i = 0; i < len1 + len2; i++) {
            if (res[i] >= 10) {
                int temp = res[i];
                res[i] = temp % 10;
                res[i + 1] += temp / 10;
            }
        }

        std::string result;
        for (int i = len1 + len2 - 1; i >= 0; i--) {
            if (i == len1 + len2 - 1 && res[i] == 0) continue;
            result += res[i] + '0';
        }
        return result;
    }
};

int main43() {
    std::string num1 = "2";
    std::string num2 = "0";

    Solution sol;
    std::cout << sol.multiply(num1, num2);

    return 0;
}
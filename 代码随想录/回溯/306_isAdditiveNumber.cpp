#include <iostream>
#include <vector>
#include <sstream>

//
// Created by polarnight on 23-10-14, 下午9:11.
//

class Solution {
public:
    std::string num;
    int n;

    bool isAdditiveNumber(std::string _num) {
        num = _num;
        n = _num.size();

        for (int len1 = 1; len1 <= n / 2; len1++) {
            for (int len2 = 1; len2 <= (n - len1) / 2; len2++) {
                if ((len1 > 1 && num[0] == '0') || (len2 > 1 && num[len1] == '0'))
                    continue;

                long long num1 = stoll(num.substr(0, len1));
                long long num2 = stoll(num.substr(len1, len2));
                int start = len1 + len2;
                if (isAdditive(start, num1, num2))
                    return true;
            }
        }
        return false;
    }

    bool isAdditive(int start, long long num1, long long num2) {
        while (start < n) {
            long long sum = num1 + num2;
            std::string sumStr = std::to_string(sum);
            if (num.compare(start, sumStr.length(), sumStr) != 0)
                return false;

            start += sumStr.length();
            num1 = num2;
            num2 = sum;
        }
        return true;
    }
};


int main306() {
    std::string num = "199100199";

    Solution sol;
    std::cout << sol.isAdditiveNumber(num);

    return 0;
}
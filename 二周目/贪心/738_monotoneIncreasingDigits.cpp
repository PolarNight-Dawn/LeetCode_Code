#include <iostream>
#include <vector>
#include <cmath>

//
// Created by polarnight on 23-10-23, 下午2:50.
//

class Solution {
public:
    // 时间复杂度O(n * N), N 为需要赋值为9的数字个数 空间复杂度为O(logn)，数组大小跟n的位数相关
    // int monotoneIncreasingDigits(int n) {
    //     if (n < 10) return n;
    //     std::vector<int> tmp;
    //
    //     while (n != 0) {
    //         tmp.push_back(n % 10);
    //         n /= 10;
    //     }
    //
    //     int pre = tmp[0];
    //     for (int i = 1; i < tmp.size(); i++) {
    //         if (pre < tmp[i]) {
    //             int index = i - 1;
    //             while (index >= 0) tmp[index--] = 9;
    //             tmp[i] -= 1;
    //         }
    //         pre = tmp[i];
    //     }
    //
    //     int ans = 0;
    //     for (int i = 0; i < tmp.size(); i++) {
    //         ans += tmp[i] * pow(10, i);
    //     }
    //     return ans;
    // }

    // 优化代码
    // 字符串更加方便 省去向量最后组合的过程 并且只有遇到降序情况才会改动数位
    // 时间复杂度O(n) 空间复杂度为O(logn)
    int monotoneIncreasingDigits(int n) {
        std::string str = std::to_string(n);
        int flag = str.size();

        for (int i = str.size() - 1; i >= 0; i--) {
            if (str[i - 1] > str[i]) {
                flag = i;
                str[i - 1]--;
            }
        }

        for (int i = flag; i < str.size(); i++) str[i] = '9';

        return stoi(str);
    }
};

int main738() {
    int n = 312;

    Solution sol;
    std::cout << sol.monotoneIncreasingDigits(n);

    return 0;
}
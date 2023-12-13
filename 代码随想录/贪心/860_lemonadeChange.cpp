#include <iostream>
#include <vector>

//
// Created by polarnight on 23-10-19, 下午4:36.
//

class Solution {
public:
    // 时间复杂度为O(n) 空间复杂度为O(n)
    // bool lemonadeChange(std::vector<int>& bills) {
    //     std::vector<int> balance(3, 0);
    //     for (int i = 0;i < bills.size(); i++) {
    //         if (i == 0 && bills[i] > 5) return false;
    //         if (bills[i] == 5) balance[0] += 1;
    //         else if (bills[i] == 10) balance[0] -= 1, balance[1] += 1;
    //         else if (bills[i] == 20) {
    //             if (balance[1] > 0)balance[0] -= 1, balance[1] -= 1, balance[2] += 1;
    //             else if (balance[1] == 0) balance[0] -= 3, balance[2] += 1;
    //         }
    //         if (balance[0] < 0 || balance[1] < 0) return false;
    //     }
    //
    //     return true;
    // }

    // 优化代码 时间复杂度为O(n) 空间复杂度为O(1)
    bool lemonadeChange(std::vector<int>& bills) {
        int five = 0, ten = 0, twenty = 0;
        for (auto &vec : bills) {
            if (vec == 5) five++;
            else if (vec == 10) five--, ten++;
            else if (vec == 20) {
                if (ten > 0) five--, ten--, twenty++;
                else if (ten == 0) five -= 3, twenty++;
            }
            if (five < 0 || ten < 0) return false;
        }
        return true;
    }
};

int main860() {
    std::vector<int> bills = {5,5,10,20,5,5,5,5,5,5,5,5,5,10,5,5,20,5,20,5};

    Solution sol;
    std::cout << sol.lemonadeChange(bills);

    return 0;
}
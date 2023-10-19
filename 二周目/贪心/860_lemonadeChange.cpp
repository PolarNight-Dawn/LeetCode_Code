#include <iostream>
#include <vector>

//
// Created by polarnight on 23-10-19, 下午4:36.
//

class Solution {
public:
    bool lemonadeChange(std::vector<int>& bills) {
        std::vector<int> balance(3, 0);
        for (int i = 0;i < bills.size(); i++) {
            if (i == 0 && bills[i] > 5) return false;
            if (bills[i] == 5) balance[0] += 1;
            else if (bills[i] == 10) balance[0] -= 1, balance[1] += 1;
            else if (bills[i] == 20) {
                if (balance[1] > 0)balance[0] -= 1, balance[1] -= 1, balance[2] += 1;
                else if (balance[1] == 0) balance[0] -= 3, balance[2] += 1;
            }
            if (balance[0] < 0 || balance[1] < 0) return false;
        }

        return true;
    }
};

int main() {
    std::vector<int> bills = {5,5,10,20,5,5,5,5,5,5,5,5,5,10,5,5,20,5,20,5};

    Solution sol;
    std::cout << sol.lemonadeChange(bills);

    return 0;
}
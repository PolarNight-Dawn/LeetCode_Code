#include <iostream>

//
// Created by polarnight on 23-9-4.
//

class Solution {
public:
    bool isPerfectSquare(int num) {
        int left = 0;
        int right = num;

        while (left <= right) {
            int mid = (right + left) / 2;
            long num_sqrt = (long)mid * mid;
            if (num_sqrt < num) left = mid + 1;
            else if (num_sqrt > num) right = mid - 1;
            else if (num_sqrt == num) return true;
        }

        return false;
    }
};

int mian367() {
    int num = 16;

    Solution sol;
    std::cout << sol.isPerfectSquare(num);

    return 0;
}
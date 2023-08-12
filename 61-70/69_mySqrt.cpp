#include <iostream>

//
// Created by polarnight on 23-8-9.
//

class Solution {
public:
    int getSqrt(long left, long right, int x) {
        long mid = (left + right) / 2;
        long sqrt = mid * mid;

        if (left == mid) return left;

        if (sqrt > x) return  getSqrt(left, mid, x);
        else if (sqrt < x) return getSqrt(mid, right, x);
        else return mid;
    }

    int mySqrt(int x) {
        if (x == 0 || x == 1) return x;
        int ans = getSqrt(0, x, x);

        return ans;
    }
};

int main() {
    int x = 1;

    Solution sol;
    std::cout << sol.mySqrt(x);

    return 0;
}
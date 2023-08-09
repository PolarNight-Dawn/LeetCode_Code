#include <iostream>

//
// Created by polarnight on 23-8-9.
//

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return x;

        long ans = 0;
        long mul = 0;
        while (mul < x) {
            ans++;
            mul = ans * ans;
        }

        if (mul != x) ans--;

        return ans;
    }
};

int main69() {
    int x = 2147483647;

    Solution sol;
    std::cout << sol.mySqrt(x);

    return 0;
}
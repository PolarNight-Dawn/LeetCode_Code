#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
//
// Created by polarnight on 23-12-24, 下午2:14.
//

class Solution {
public:
    //! \究极数学推导
    // long long minimumPerimeter(long long neededApples) {
    //      long long n = cbrt(neededApples / 4.0);
    //
    //      if (2 * n * (n + 1) * (2 * n + 1) < neededApples) n++;
    //
    //     return n * 8;
    //  }

    //! \二分法and数学
    long long minimumPerimeter(long long neededApples) {
        long long left = 1, right = 99999;

        while (left <= right) {
            long long mid = left + (right - left) / 2;
            if (2 * mid * (mid + 1) * (2 * mid + 1) >= neededApples) right = mid - 1;
            else left = mid + 1;
        }
        return left * 8;
    }
};

int main231224() {
    long long neededApples = 1000000000;

    Solution sol;
    cout << sol.minimumPerimeter(neededApples);

    return 0;
}
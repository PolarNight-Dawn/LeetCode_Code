#include <iostream>
#include <vector>
#include <cmath>

//
// Created by polarnight on 23-10-23, 下午2:50.
//

class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        if (n < 10) return n;
        std::vector<int> tmp;

        while (n != 0) {
            tmp.push_back(n % 10);
            n /= 10;
        }

        int pre = tmp[0];
        for (int i = 1; i < tmp.size(); i++) {
            if (pre < tmp[i]) {
                int index = i - 1;
                while (index >= 0) tmp[index--] = 9;
                tmp[i] -= 1;
            }
            pre = tmp[i];
        }

        int ans = 0;
        for (int i = 0; i < tmp.size(); i++) {
            ans += tmp[i] * pow(10, i);
        }
        return ans;
    }
};

int main() {
    int n = 312;

    Solution sol;
    std::cout << sol.monotoneIncreasingDigits(n);

    return 0;
}
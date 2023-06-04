#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
//
// Created by polarnight on 23-4-16.
//

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        long temp = x;
        long rev = 0;
        int digit = 0;
        while (temp > 0) {
            digit = temp % 10;
            temp /= 10;
            rev = rev * 10 + digit;
        }

        if (rev == x) return true;

        return false;
    }
};

int main09() {
    int x = 121;

    Solution sol;
    cout << sol.isPalindrome(x);

    return 0;
}
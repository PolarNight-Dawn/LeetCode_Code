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
        if (x < 0) {
            return false;
        }

        string s = to_string(x);
        string r = s;
        reverse(r.begin(), r.end());

        return s == r;
    }
};

int main09 () {
    int x = 10;

    Solution sol;
    cout << sol.isPalindrome(x);

    return 0;
}
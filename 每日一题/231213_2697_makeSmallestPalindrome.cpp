#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//
// Created by polarnight on 23-12-13, 下午3:22.
//

class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int left = 0, right = s.size() - 1;

        while (left < right) {
            if (s[left] != s[right]) {
                if (s[left] > s[right]) s[left] = s[right];
                if (s[left < s[right]]) s[right] = s[left];
            }
            left++, right--;
        }
        return s;
    }
};

int main() {
    string s = "egcfe";

    Solution sol;
    auto  result = sol.makeSmallestPalindrome(s);

    cout << result << endl;
    return 0;
}
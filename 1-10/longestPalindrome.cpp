#include <iostream>
#include <vector>

using namespace std;
//
// Created by polarnight on 23-4-12.
//

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if (n < 2) {
            return s;
        }

        int start = 0, maxLen = 1;
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        for (int i = n-1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j]) {
                    if (j - i < 2) {
                        dp[i][j] = true;
                    } else {
                        dp[i][j] = dp[i+1][j-1];
                    }
                } else {
                    dp[i][j] = false;
                }

                if (dp[i][j] && j - i + 1 > maxLen) {
                    start = i;
                    maxLen = j - i + 1;
                }
            }
        }

        return s.substr(start, maxLen);
    }
};


int main () {
    string s = "abba";

    Solution sol;
    cout << sol.longestPalindrome(s);

    return 0;
}
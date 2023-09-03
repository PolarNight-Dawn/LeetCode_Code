#include <iostream>
#include <vector>

//
// Created by polarnight on 23-9-3.
//

// Definition of a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(nullptr), right(nullptr) {}

};

class Solution {
public:
    int numDistinct(std::string s, std::string t)
    {
        int m = s.size();
        int n = t.size();
        if (m < n) return 0;

        std::vector<std::vector<unsigned long long>> dp(m+1, std::vector<unsigned long long>(n+1, 0));
        for (int i = 0; i <= m; ++i)
        {
            dp[i][0] = 1;
        }
        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (s[i-1] == t[j-1])
                {
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[m][n] > INT32_MAX? -1: dp[m][n];
    }
};

int main() {
    std::string s = "rabbbit";
    std::string t = "rabbit";

    Solution sol;
    std::cout << sol.numDistinct(s, t);

    return 0;
}
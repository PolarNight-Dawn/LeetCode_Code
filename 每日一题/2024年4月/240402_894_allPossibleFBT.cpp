//
// Created by polarnight on 24-4-2, 下午3:05.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


/*Definition for a binary tree node.*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<TreeNode *> allPossibleFBT(int n) {
        vector<TreeNode *> res;
        if ((n & 1) == 0) return res;
        if (n == 1) {
            res.push_back(new TreeNode(0));
            return res;
        }

        for (int i = 1; i <= n - 2; i += 2) {
            vector<TreeNode *> left = allPossibleFBT(i);
            vector<TreeNode *> right = allPossibleFBT(n - 1 - i);

            for (auto &j: left) {
                for (auto &k: right) {
                    auto root = new TreeNode(0);
                    root->left = j;
                    root->right = k;
                    res.push_back(root);
                }
            }
        }
        return res;
    }
};

int main240402_894() {
    int n = 7;

    Solution sol;
    auto res = sol.allPossibleFBT(n);

    cout << "test";

    return 0;
}
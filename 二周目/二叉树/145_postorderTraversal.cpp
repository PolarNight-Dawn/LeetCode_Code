#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

//
// Created by polarnight on 23-9-27, 下午2:20.
//

// Definition for a binary tree node.
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
    std::vector<int> postorderTraversal(TreeNode* root) {
        std::stack<TreeNode *> sta;
        std::vector<int> res;
        if (root == nullptr) return res;

        sta.push(root);
        while(!sta.empty()) {
            TreeNode *node = sta.top();
            sta.pop();
            res.push_back(node->val);
            if (node->left) sta.push(node->left);
            if (node->right) sta.push(node->right);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main145() {
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution sol;
    std::vector<int> res = sol.postorderTraversal(root);

    for (auto &vec : res) {
        std::cout << vec << " ";
    }

    return 0;
}
#include <iostream>
#include <vector>

//
// Created by polarnight on 23-8-23.
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
    void inorderTraversal(std::vector<int> &res, TreeNode* root) {
        if (root == nullptr) return;

        inorderTraversal(res, root->left);
        res.push_back(root->val);
        inorderTraversal(res,root->right);
    }

    std::vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> res;
        inorderTraversal(res, root);

        return  res;
    }
};

int main94() {
    TreeNode *left = new TreeNode(3);
    TreeNode *right = new TreeNode(2, left, nullptr);
    TreeNode *root = new TreeNode(1, nullptr, right);

    Solution sol;
    std::vector<int> res = sol.inorderTraversal(root);

    for (auto &vec : res) {
        std::cout << vec << " ";
    }

    return  0;
}
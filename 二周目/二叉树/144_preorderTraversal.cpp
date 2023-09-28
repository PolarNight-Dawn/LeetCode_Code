#include <iostream>
#include <vector>

//
// Created by polarnight on 23-9-26, 下午9:14.
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
    void Preorder(std::vector<int> &res, TreeNode *root) {
        if (root == nullptr) return;

        res.push_back(root->val);

        Preorder(res, root->left);

        Preorder(res, root->right);
    }

    std::vector<int> preorderTraversal(TreeNode* root) {
        std::vector<int> res;

        Preorder(res, root);

        return res;
    }
};

int main144() {
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution sol;
    std::vector<int> res = sol.preorderTraversal(root);

    for (auto &vec : res) {
        std::cout << vec << " ";
    }

    return 0;
}
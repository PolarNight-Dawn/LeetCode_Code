#include <iostream>
#include <vector>
#include <algorithm>

//
// Created by polarnight on 23-10-2, 下午5:43.
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
    TreeNode *constructMaximumBinaryTree(std::vector<int> &nums) {
        auto max_it = std::max_element(nums.begin(), nums.end());
        int max_val = *max_it;
        int max_index = std::distance(nums.begin(), max_it);
        TreeNode *node = new TreeNode(max_val);
        nums.erase(max_it);

        // auto pivot = std::partition(nums.begin(), nums.end(),
        //                             [=](int i) { return i < max_val; });

        std::vector<int> left(nums.begin(), nums.begin() + max_index);
        std::vector<int> right(nums.begin() + max_index, nums.end());

        if (!left.empty()) node->left = constructMaximumBinaryTree(left);
        if (!right.empty()) node->right = constructMaximumBinaryTree(right);

        return node;
    }
};

int main() {
    std::vector<int> nums = {3, 2, 1, 6, 0, 5};

    Solution sol;
    TreeNode *root = sol.constructMaximumBinaryTree(nums);

    return 0;
}
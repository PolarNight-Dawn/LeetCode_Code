#include <iostream>
#include <vector>

//
// Created by polarnight on 23-8-30.
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
    TreeNode *build_tree(std::vector<int>& nums, int left, int right) {
        if (left > right) return nullptr;

        int mid = left + (right - left) / 2;
        TreeNode *root = new TreeNode(nums[mid]);

        root->left = build_tree(nums, left, mid - 1);
        root->right = build_tree(nums, mid + 1, right);

        return root;
    }

    TreeNode* sortedArrayToBST(std::vector<int>& nums) {
        return build_tree(nums, 0, nums.size() - 1);
    }
};

int main108() {
    std::vector<int> nums = {-10,-3,0,5,9};

    Solution sol;
    TreeNode *root = sol.sortedArrayToBST(nums);

    return 0;
}
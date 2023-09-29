#include <iostream>

//
// Created by polarnight on 23-9-29, 下午2:51.
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
    bool IsSameTree(TreeNode *root, TreeNode *sub_root) {
        if (!root && !sub_root) return true;
        return root && sub_root && root->val == sub_root->val &&
               (IsSameTree(root->left, sub_root->left)) &&
               (IsSameTree(root->right, sub_root->right));
    }

    bool isSubtree(TreeNode *root, TreeNode *subRoot) {
        if (!root || !subRoot) return false;
        if (IsSameTree(root, subRoot)) return true;
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};

int main() {
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(4);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(2);
    root->right = new TreeNode(5);

    TreeNode *sub_root = new TreeNode(4);
    sub_root->left = new TreeNode(1);
    sub_root->right = new TreeNode(2);

    Solution sol;
    std::cout << sol.isSubtree(root, sub_root);

    return 0;
}
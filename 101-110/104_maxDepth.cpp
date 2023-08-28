#include <iostream>

//
// Created by polarnight on 23-8-28.
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
    int find_height(TreeNode *root) {
        if (root == nullptr) return 0;

        int height = std::max(find_height(root->left), find_height(root->right)) + 1;

        return height;
    }

    int maxDepth(TreeNode* root) {
        return find_height(root);
    }
};

int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    // root->left->right = new TreeNode(4);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(5);
    // root->right->right = new TreeNode(3);

    Solution sol;
    std::cout << sol.maxDepth(root);

    return 0;
}
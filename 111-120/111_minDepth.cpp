#include <iostream>

//
// Created by polarnight on 23-9-1.
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
    int find_height02(TreeNode *root) {
        if (root == nullptr) return 0;

        if (root->left == nullptr && root->right == nullptr) return 1;

        if (root->left == nullptr) return find_height02(root->right) + 1;

        if (root->right == nullptr) return find_height02(root->left) + 1;

        int height = std::min(find_height02(root->left), find_height02(root->right)) + 1;

        return height;
    }

    int minDepth(TreeNode *root) {
        return find_height02(root);
    }
};

int main() {
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution sol;
    std::cout << sol.minDepth(root);

    return 0;
}

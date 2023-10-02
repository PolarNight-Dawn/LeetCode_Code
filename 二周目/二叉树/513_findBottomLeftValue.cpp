#include <iostream>
#include <queue>
#include <vector>

//
// Created by polarnight on 23-10-2, 下午4:13.
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
    int findBottomLeftValue(TreeNode *root) {
        TreeNode *node;
        std::queue<TreeNode *> que;

        que.push(root);
        while (!que.empty()) {
            node = que.front();
            que.pop();
            if (node->right) que.push(node->right);
            if (node->left)  que.push(node->left);
        }
        return node->val;
    }
};

int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(5);
    root->right->left->left = new TreeNode(7);
    root->right->right = new TreeNode(7);

    Solution sol;
    std::cout << sol.findBottomLeftValue(root);

    return 0;
}
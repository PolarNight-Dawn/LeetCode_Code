#include <iostream>
#include <algorithm>

//
// Created by polarnight on 23-9-28, 下午1:04.
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
    // void dfs(TreeNode *&root) {
    //     if (!root) return;
    //
    //     // if (root->right || root->left) {
    //     //     TreeNode *tmp = root->left;
    //     //     root->left = root->right;
    //     //     root->right = tmp;
    //     // }
    //
    //     if (root->right || root->left) std::swap(root->left, root->right);
    //     dfs(root->left);
    //     dfs(root->right);
    // }
    //
    // TreeNode* invertTree(TreeNode* root) {
    //     TreeNode *node = root;
    //
    //     dfs(node);
    //
    //     return root;
    // }

    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) return root;
        std::swap(root->left, root->right);  // 中
        invertTree(root->left);         // 左
        invertTree(root->right);        // 右
        return root;
    }
};

int main() {
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right = new TreeNode(7);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);

    Solution sol;
    TreeNode *node = sol.invertTree(root);

    return 0;
}
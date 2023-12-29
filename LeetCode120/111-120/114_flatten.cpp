#include <iostream>

//
// Created by polarnight on 23-9-3.
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
    void flatten(TreeNode* root) {
        if (!root) return;

        // 保存右子树
        TreeNode* rightSubtree = root->right;

        // 递归处理左子树，将左子树转换为链表
        flatten(root->left);

        // 将左子树转换后的链表插入到根节点和右子树之间
        root->right = root->left;
        root->left = nullptr;

        // 找到转换后的链表的尾部
        TreeNode* current = root;
        while (current->right) {
            current = current->right;
        }

        // 将原右子树接到链表的尾部
        current->right = rightSubtree;

        // 递归处理原右子树
        flatten(rightSubtree);
    }
};

int main114() {
    TreeNode *root = new TreeNode(5);
    root->right = new TreeNode(8);
    root->right->right = new TreeNode(4);
    root->right->left = new TreeNode(13);
    root->right->right->right = new TreeNode(1);
    root->left = new TreeNode(4);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);

    Solution sol;
    sol.flatten(root);

    while (root != nullptr) {
        std::cout << root->val << " ";
        root = root->right;
    }

    return 0;
}
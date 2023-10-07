#include <iostream>

//
// Created by polarnight on 23-10-7, 下午9:56.
//

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor02(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return nullptr;

        if (p->val <= q->val) {
            if (root->val >= p->val && root->val <= q->val) return root;
        } else {
            if (root->val >= q->val && root->val <= p->val) return root;
        }

        TreeNode *left = lowestCommonAncestor02(root->left, p, q);
        TreeNode *right = lowestCommonAncestor02(root->right, p, q);

        if (!left) return right;
        if (!right) return left;

        return root;
    }
};

int main() {
    TreeNode *root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);
    root->right = new TreeNode(8);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);

    TreeNode *p = root->left;
    TreeNode *q = root->right;
    Solution sol;
    TreeNode *node = sol.lowestCommonAncestor02(root, p, q);

    std::cout << node->val;

    return 0;
}
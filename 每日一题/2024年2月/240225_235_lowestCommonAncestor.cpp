#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//
// Created by polarnight on 24-2-25, 下午9:49.
//


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    TreeNode* lowestCommonAncestor240225235(TreeNode* root, TreeNode* p, TreeNode* q) {
        int x = root->val;
        if (p->val < x && q->val < x) return lowestCommonAncestor240225235(root->left, p, q);
        if (p->val > x && q->val > x) return lowestCommonAncestor240225235(root->right, p, q);
        return root;
    }
};

void deleteTreeNode02(TreeNode *root) {
    if (!root) return;

    deleteTreeNode02(root->left);
    deleteTreeNode02(root->right);

    delete root;
}

int main240225235() {
    TreeNode *root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);

    root->right = new TreeNode(8);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);

    TreeNode *p = new TreeNode(2);
    TreeNode *q = new TreeNode(8);

    Solution sol;
    auto res = sol.lowestCommonAncestor240225235(root, p, q);

    cout << res->val << endl;

    deleteTreeNode02(root);
    deleteTreeNode02(p);
    deleteTreeNode02(q);

    return 0;
}
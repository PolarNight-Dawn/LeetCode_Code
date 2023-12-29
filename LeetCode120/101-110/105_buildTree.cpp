#include <iostream>
#include <vector>
#include <algorithm>

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
    TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
        if (preorder.empty() || inorder.empty()) return nullptr;
        TreeNode* root = new TreeNode(preorder[0]);

        auto it = std::find(inorder.begin(), inorder.end(), preorder[0]);

        if (it != inorder.end()) {
            int index = std::distance(inorder.begin(), it);

            std::vector<int> inorder_left, preorder_left, inoeder_right, preorder_right;
            inorder_left.assign(inorder.begin(), inorder.begin() + index);
            preorder_left.assign(preorder.begin() + 1, preorder.begin() + index + 1);
            root->left = buildTree(preorder_left, inorder_left);
            inoeder_right.assign(inorder.begin() + index + 1, inorder.end());
            preorder_right.assign(preorder.begin() + index + 1, preorder.end());
            root->right = buildTree(preorder_right, inoeder_right);
        }

        return root;
    }
};

void mid_order(TreeNode *root) {
    if (root == nullptr) return;

    mid_order(root->left);
    std::cout << root->val << " ";
    return mid_order(root->right);
}

int main105() {
    std::vector<int> preorder = {3,9,20,15,7};
    std::vector<int> inorder = {9,3,15,20,7};

    Solution sol;
    TreeNode *root = sol.buildTree(preorder, inorder);

    mid_order(root);

    return 0;
}
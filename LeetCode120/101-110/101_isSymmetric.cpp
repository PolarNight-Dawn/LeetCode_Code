#include <iostream>
#include <vector>

//
// Created by polarnight on 23-8-26.
//

// Definition of a binary tree node
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
    void mid_order_traversal(TreeNode *root, std::vector<int> &tmp, int flag) {
        if (root == nullptr) return;

        mid_order_traversal(root->left, tmp, 1);

        tmp.push_back(root->val * flag);

        mid_order_traversal(root->right, tmp, -1);
    }

    bool isSymmetric(TreeNode* root) {
        std::vector<int> tmp;

        mid_order_traversal(root, tmp, 1);

        if (tmp.size() % 2 == 0) return false;
        for (int i = 0, j = tmp.size() - 1; i < j; i++, j--) {
            if (tmp[i] != -tmp[j]) return false;
        }

        return true;
    }
};

int main101() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    Solution sol;
    std::cout << sol.isSymmetric(root);

    return 0;
}
#include <iostream>
#include <vector>
#include <queue>

//
// Created by polarnight on 23-9-27, 下午3:15.
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
    void bfs(std::vector<int> &res, TreeNode *root) {
        std::queue<TreeNode *> queue;
        if (root != nullptr) queue.push(root);

        while (!queue.empty()) {
            int len = queue.size();
            for (int i = 0; i < len; i++) {
                TreeNode *node = queue.front();
                queue.pop();
                if (node != nullptr && i == len - 1) res.push_back(node->val);
                if (node != nullptr && node->left != nullptr) queue.push(node->left);
                if (node != nullptr && node->right != nullptr) queue.push(node->right);
            }
        }
    }

    std::vector<int> rightSideView(TreeNode* root) {
        std::vector<int> res;

        bfs(res, root);

        return res;
    }
};

int main199() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->right = new TreeNode(5);
    root->right = new TreeNode(3);
    root->right->right = new TreeNode(4);

    Solution sol;
    std::vector<int> res = sol.rightSideView(root);

    for (auto &vec : res) {
        std::cout << vec << " ";
    }

    return 0;
}
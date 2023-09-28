#include <iostream>
#include <vector>
#include <queue>

//
// Created by polarnight on 23-9-27, 下午8:13.
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
    void bfs02(std::vector<int> &res, TreeNode *root) {
        std::queue<TreeNode *> queue;
        if (root != nullptr) queue.push(root);

        while (!queue.empty()) {
            int max_num = INT32_MIN;
            int len = queue.size();
            for (int i = 0; i < len; i++) {
                TreeNode *node = queue.front();
                queue.pop();
                if (node != nullptr) max_num = std::max(max_num, node->val);
                if (node != nullptr && node->left != nullptr) queue.push(node->left);
                if (node != nullptr && node->right != nullptr) queue.push(node->right);
                if (i == len - 1) res.push_back(max_num);
            }
        }
    }

    std::vector<int> largestValues(TreeNode* root) {
        std::vector<int> res;

        if (root) bfs02(res, root);

        return res;
    }
};

int main515() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->right = new TreeNode(5);
    root->right = new TreeNode(3);
    root->right->right = new TreeNode(4);

    Solution sol;
    std::vector<int> res = sol.largestValues(root);

    for (auto &vec : res) {
        std::cout << vec << " ";
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <queue>

//
// Created by polarnight on 23-9-27, 下午7:10.
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
    void bfs(std::vector<double> &res, TreeNode *root) {
        std::queue<TreeNode *> queue;
        if (root != nullptr) queue.push(root);

        while (!queue.empty()) {
            long long sum = 0;
            int len = queue.size();
            for (int i = 0; i < len; i++) {
                TreeNode *node = queue.front();
                queue.pop();
                if (node != nullptr) sum += node->val;
                if (node != nullptr && node->left != nullptr) queue.push(node->left);
                if (node != nullptr && node->right != nullptr) queue.push(node->right);
                if (i == len - 1) {
                    double aver = static_cast<double >(sum) / len;
                    res.push_back(aver);
                }
            }
        }
    }

    std::vector<double> averageOfLevels(TreeNode* root) {
        std::vector<double> res;

        bfs(res, root);

        return res;
    }
};

int main637() {
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution sol;
    std::vector<double> res = sol.averageOfLevels(root);

    for (auto &vec : res) {
        std::cout << vec << " ";
    }

    return 0;
}
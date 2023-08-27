#include <iostream>
#include <vector>
#include <queue>

//
// Created by polarnight on 23-8-27.
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
    void bfs(std::vector<std::vector<int>> &res, TreeNode *root) {
        std::queue<TreeNode *> queue;
        if (root != nullptr) queue.push(root);

        while (!queue.empty()) {
            int len = queue.size();
            std::vector<int> tmp;
            for (int i = 0; i < len; i++) {
                TreeNode *node = queue.front();
                queue.pop();
                if (node != nullptr) tmp.push_back(node->val);
                if (node != nullptr && node->left != nullptr) queue.push(node->left);
                if (node != nullptr && node->right != nullptr) queue.push(node->right);
                if (i == len - 1) res.push_back(tmp);
            }
        }
    }

    std::vector<std::vector<int>> levelOrder(TreeNode *root) {
        std::vector<std::vector<int>> res;

        bfs(res, root);

        return res;
    }
};

int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    Solution sol;
    std::vector<std::vector<int>> res = sol.levelOrder(root);

    for (auto &tmp : res) {
        for (auto &vec : tmp) {
            std::cout << vec << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
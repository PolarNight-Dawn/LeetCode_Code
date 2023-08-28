#include <iostream>
#include <vector>
#include <deque>

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
    void bfs02(std::vector<std::vector<int>> &res, TreeNode *root) {
        std::deque<TreeNode *> deque;
        if (root != nullptr) deque.push_back(root);

        bool cnt = true;
        while (!deque.empty()) {
            int len = deque.size();
            std::vector<int> tmp;

            for (int i = 0; i < len; i++) {
                if (cnt) {
                    TreeNode *node = deque.front();
                    deque.pop_front();
                    if (node != nullptr) tmp.push_back(node->val);
                    if (node != nullptr && node->left != nullptr) deque.push_back(node->left);
                    if (node != nullptr && node->right != nullptr) deque.push_back(node->right);
                } else {
                    TreeNode *node = deque.back();
                    deque.pop_back();
                    if (node != nullptr) tmp.push_back(node->val);
                    if (node != nullptr && node->right != nullptr) deque.push_front(node->right);
                    if (node != nullptr && node->left != nullptr) deque.push_front(node->left);
                }
                if (i == len - 1) res.push_back(tmp);
            }
            cnt = !cnt;
        }
    }

    std::vector<std::vector<int>> zigzagLevelOrder(TreeNode *root) {
        std::vector<std::vector<int>> res;

        bfs02(res, root);

        return res;
    }
};

int main103() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    // root->left->right = new TreeNode(4);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(5);
    // root->right->right = new TreeNode(3);

    Solution sol;
    std::vector<std::vector<int>> res = sol.zigzagLevelOrder(root);

    for (auto &tmp : res) {
        for (auto &vec : tmp) {
            std::cout << vec << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
#include <iostream>
#include <vector>

//
// Created by polarnight on 23-8-23.
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
    std::vector<TreeNode*> getRes(int start, int end) {
        std::vector<TreeNode*> res;
        if (start > end) {
            res.push_back(nullptr);
            return res;
        }

        if (start == end) {
            TreeNode *tree = new TreeNode(start);
            res.push_back(tree);
            return res;
        }

        for (int i = start; i <= end; i++) {
            std::vector<TreeNode*> left_trees = getRes(start, i - 1);
            std::vector<TreeNode*> right_trees = getRes(i + 1, end);
            for (auto &left_trees : left_trees) {
                for (auto &right_trees : right_trees) {
                    TreeNode *root = new TreeNode(i);
                    root->left = left_trees;
                    root->right = right_trees;
                    res.push_back(root);
                }
            }
        }

        return res;
    }

    std::vector<TreeNode*> generateTrees(int n) {
        std::vector<TreeNode*> res;

        if (n == 0) return res;

        return getRes(1, n);
    }
};

void print_binary_tree(TreeNode *root) {
    if (root == nullptr) {
        std::cout << "nullptr";
        return;
    }

    std::cout << root->val << " [";
    print_binary_tree(root->left);
    std::cout << ", ";
    print_binary_tree(root->right);
    std::cout << "] ";
}

void release_binary_tree(TreeNode *root) {
    if (root == nullptr) return;

    release_binary_tree(root->left);
    release_binary_tree(root->right);
    delete root;
}

int main95() {
    int n = 3;

    Solution sol;
    std::vector<TreeNode*> res = sol.generateTrees(n);

    for (auto &root : res) {
        print_binary_tree(root);
        std::cout << std::endl;
        release_binary_tree(root);
    }

    return 0;
}

#include <iostream>
#include <vector>

//
// Created by polarnight on 23-9-2.
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
    void record_path(std::vector<std::vector<int>> &res, std::vector<int> &tmp,
                     TreeNode *root, int sum) {
        if (root == nullptr) return;

        if (!root->left && !root->right) {
            if (sum == 0) res.push_back(tmp);
            return;
        }

        if (root->left) {
            sum -= root->left->val;
            tmp.push_back(root->left->val);
            record_path(res, tmp, root->left, sum);
            tmp.pop_back();
            sum += root->left->val;
        }

        if (root->right) {
            sum -= root->right->val;
            tmp.push_back(root->right->val);
            record_path(res, tmp, root->right, sum);
            tmp.pop_back();
            sum += root->right->val;
        }
        return;
    }

    std::vector<std::vector<int>> pathSum(TreeNode *root, int targetSum) {
        std::vector<std::vector<int>> res;
        std::vector<int> tmp;

        if (root == nullptr) return res;
        tmp.push_back(root->val);
        record_path(res, tmp, root, targetSum - root->val);

        return res;
    }
};

int main() {
    TreeNode *root = new TreeNode(5);
    root->right = new TreeNode(8);
    root->right->right = new TreeNode(4);
    root->right->left = new TreeNode(13);
    root->right->right->right = new TreeNode(1);
    root->left = new TreeNode(4);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);

    int targetSum = 22;

    Solution sol;
    std::vector<std::vector<int>> res = sol.pathSum(root, targetSum);

    for (auto &tmp : res) {
        for (auto &vec : tmp) {
            std::cout << vec << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
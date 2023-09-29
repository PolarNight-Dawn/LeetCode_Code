#include <iostream>
#include <vector>

//
// Created by polarnight on 23-9-29, 下午4:40.
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
    void FindAllPaths(std::vector<std::string> &res, std::string tmp, TreeNode *root) {
        if (!root) {
            tmp.pop_back();
            tmp.pop_back();
            res.push_back(tmp);
            tmp.pop_back();
            return;
        }

        tmp += std::to_string(root->val) + "->";

        if (!root->left && root->right) FindAllPaths(res, tmp, root->right);
        else if (root->left && !root->right) FindAllPaths(res, tmp, root->left);
        else if (!root->left && !root->right) FindAllPaths(res, tmp, root->left);
        else {
            FindAllPaths(res, tmp, root->left);
            FindAllPaths(res, tmp, root->right);
        }
    }

    std::vector<std::string> binaryTreePaths(TreeNode *root) {
        std::vector<std::string> res;
        std::string tmp;

        FindAllPaths(res, tmp, root);

        return res;
    }
};

int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);

    Solution sol;
    std::vector<std::string> res = sol.binaryTreePaths(root);

    for (auto &vec : res) {
        std::cout << vec << " ";
    }

    return 0;
}
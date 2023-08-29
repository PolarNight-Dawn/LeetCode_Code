#include <iostream>
#include <vector>
#include <algorithm>

//
// Created by polarnight on 23-8-29.
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
    TreeNode* buildTree02(std::vector<int>& inorder, std::vector<int>& postorder) {
        if (inorder.empty() || postorder.empty()) return nullptr;
        TreeNode *root = new TreeNode(postorder[postorder.size() - 1]);

        auto it = std::find(inorder.begin(), inorder.end(), postorder[postorder.size() - 1]);

        if (it != inorder.end()) {
            int index = std::distance(inorder.begin(), it);

            std::vector<int> post_left, in_left, post_right, in_right;
            in_left.assign(inorder.begin(), inorder.begin() + index);
            post_left.assign(postorder.begin(), postorder.begin() + index);
            root->left = buildTree02(in_left, post_left);
            in_right.assign(inorder.begin() + index + 1, inorder.end());
            post_right.assign(postorder.begin() + index, postorder.end() - 1);
            root->right = buildTree02(in_right, post_right);
        }

        return root;
    }
};

int main() {
    std::vector<int> inorder = {9,3,15,20,7};
    std::vector<int> postorder = {9,15,7,20,3};

    Solution sol;
    TreeNode *root = sol.buildTree02(inorder, postorder);

    return 0;
}
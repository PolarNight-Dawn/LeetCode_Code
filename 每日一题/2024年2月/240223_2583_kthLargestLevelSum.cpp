#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

//
// Created by polarnight on 24-2-24, 下午3:52.
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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<TreeNode *> q;
        q.push(root);
        vector<long long> temp;
        while (!q.empty()) {
            long long sum = 0, n = q.size();
            for (int i = 0; i < n; i++) {
                TreeNode * node = q.front();
                sum += node->val;
                q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            temp.push_back(sum);
        }
        if (temp.size() < k) return -1;
        sort(temp.begin(), temp.end());
        return *(temp.end() - k);
    }
};

void deleteTreeNode(TreeNode *root) {
    if (!root) return;

    deleteTreeNode(root->left);
    deleteTreeNode(root->right);

    delete root;
}

int main2402232583() {
    TreeNode *ptr = new TreeNode(5);
    ptr->left = new TreeNode(8);
    ptr->left->left = new TreeNode(2);
    ptr->left->right = new TreeNode(1);
    ptr->left->left->left = new TreeNode(4);
    ptr->left->left->right = new TreeNode(6);

    ptr->right = new TreeNode(9);
    ptr->right->left = new TreeNode(3);
    ptr->right->right = new TreeNode(7);

    Solution sol;
    cout << sol.kthLargestLevelSum(ptr, 2);

    deleteTreeNode(ptr);

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//
// Created by polarnight on 24-2-24, 下午5:01.
//


//Definition for a binary tree node.
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
    void dfs(TreeNode *root, vector<int> &temp) {
        if (!root) return;

        dfs(root->left, temp);
        temp.push_back(root->val);
        dfs(root->right, temp);
    }

    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<int> temp;
        dfs(root, temp);
        int n = temp.size();
        vector<vector<int>> ans;

        for (auto vec : queries) {
            int cnt = lower_bound(temp.begin(), temp.end(), vec) - temp.begin();
            int mx = cnt < n ? temp[cnt] : -1;
            if (cnt == n || temp[cnt] != vec) cnt--;
            int mn = cnt >= 0 ? temp[cnt] : -1;
            ans.push_back({mn, mx});
        }
        return ans;
    }
};

void deleteTreeNode01(TreeNode* node) {
    if (!node) return;

    deleteTreeNode01(node->left);
    deleteTreeNode01(node->right);

    delete node;
}

int main2402242476() {
    TreeNode *root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(4);

    root->right = new TreeNode(13);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(15);
    root->right->right->left = new TreeNode(14);

    vector<int> queries = {2,5,16};
    Solution sol;
    auto res = sol.closestNodes(root, queries);

    deleteTreeNode01(root);

    for (auto &tmp : res) {
        for (auto &vec : tmp) {
            cout << vec << " ";
        }
    }
    cout << endl;

    return 0;
}
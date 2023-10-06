#include <iostream>
#include <vector>
#include <unordered_map>

//
// Created by polarnight on 23-10-6, 上午11:42.
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
    // 使用哈希全撸了一遍统计频率，没有利用上二叉搜索树的特性
    // 时间复杂度:O(n) 空间复杂度:O(n)
    // void Traverse(std::unordered_map<int, int> &map, TreeNode *root) {
    //     if (!root) return;
    //
    //     map[root->val]++;
    //
    //     Traverse(map, root->left);
    //     Traverse(map, root->right);
    // }
    //
    // std::vector<int> findMode(TreeNode* root) {
    //     std::unordered_map<int, int> map;
    //     std::vector<int> res;
    //
    //     Traverse(map, root);
    //
    //     int key = 0, val = 0;
    //     for (auto &vec : map) {
    //         if (vec.second > val) {
    //             val = vec.second;
    //             key = vec.first;
    //         }
    //     }
    //
    //     res.push_back(key);
    //     map.erase(key);
    //     for (auto &vec : map) {
    //         if (val == vec.second) res.push_back(vec.first);
    //     }
    //
    //     return res;
    // }

    std::vector<int> answer;
    int base, count, maxCount;

    void update(int x) {
        if (x == base) {
            ++count;
        } else {
            count = 1;
            base = x;
        }
        if (count == maxCount) {
            answer.push_back(base);
        }
        if (count > maxCount) {
            maxCount = count;
            answer = std::vector<int> {base};
        }
    }

    void dfs(TreeNode* o) {
        if (!o) {
            return;
        }
        dfs(o->left);
        update(o->val);
        dfs(o->right);
    }

    std::vector<int> findMode(TreeNode* root) {
        dfs(root);
        return answer;
    }
};

int main() {
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(2);

    Solution sol;
    std::vector<int> res = sol.findMode(root);

    for (auto &vec : res) {
        std::cout << vec << " ";
    }

    return 0;
}
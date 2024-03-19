//
// Created by polarnight on 24-3-12, 下午7:08.
//

#include <iostream>
#include <unordered_set>

using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class FindElements {
private:
    unordered_set<int> set;

    void dfs(TreeNode *node, int val) {
        if (!node) return;

        node->val = val;
        set.insert(val);
        dfs(node->left, val * 2 + 1);
        dfs(node->right, val * 2 + 2);
    }
public:
    FindElements(TreeNode* root) {
       dfs(root, 0);
    }

    bool find(int target) {
        return set.count(target) > 0;
    }
};

int main2403121261() {
    auto *root = new TreeNode(-1);
    root->right = new TreeNode(-1);

    auto *obj = new FindElements(root);
    bool param_1 = obj->find(1);
    bool param_2 = obj->find(2);

    cout << param_1 << param_2 << endl;

    delete(root);
    delete(root->right);
    delete(obj);

    return 0;
}
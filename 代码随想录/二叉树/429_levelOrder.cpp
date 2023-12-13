#include <iostream>
#include <vector>
#include <queue>

//
// Created by polarnight on 23-9-27, 下午7:28.
//

// Definition for a Node.
class Node {
public:
    int val;
    std::vector<Node *> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, std::vector<Node *> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    void bfs(std::vector<std::vector<int>> &res, Node *root) {
        std::queue<Node *> que;

        que.push(root);
        while (!que.empty()) {
            std::vector<int> tmp;
            int len = que.size();

            for (int i = 0; i < len; i++) {
                Node *node = que.front();
                que.pop();
                if (node) tmp.push_back(node->val);
                if (node) {
                    for (auto &vec: node->children) que.push(vec);
                }
                if (i == len - 1) res.push_back(tmp);
            }
        }
    }

    std::vector<std::vector<int>> levelOrder(Node *root) {
        std::vector<std::vector<int>> res;

        if (root) bfs(res, root);

        return res;
    }
};

int main429() {
    Node *root = new Node(1);
    root->children.push_back(new Node(3));
    root->children.push_back(new Node(2));
    root->children.push_back(new Node(4));
    root->children[0]->children.push_back(new Node(5));
    root->children[0]->children.push_back(new Node(6));

    Solution sol;
    std::vector<std::vector<int>> res = sol.levelOrder(root);

    for (auto &tmp: res) {
        for (auto &vec: tmp) {
            std::cout << vec << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}

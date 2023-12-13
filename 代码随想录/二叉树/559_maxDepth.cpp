#include <iostream>
#include <vector>

//
// Created by polarnight on 23-9-29, 下午3:23.
//

// Definition for a Node.
class Node {
public:
    int val;
    std::vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, std::vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    int maxDepth(Node* root) {
        if (!root) return 0;

        int depth = 0;
        for (auto &vec : root->children) {
            depth = std::max(depth, maxDepth(vec));
        }

        return depth + 1;
    }
};

int main559() {
    Node *root = new Node(1);
    root->children.push_back(new Node(3));
    root->children.push_back(new Node(2));
    root->children.push_back(new Node(4));
    root->children[0]->children.push_back(new Node(5));
    root->children[0]->children.push_back(new Node(6));

    Solution sol;
    std::cout << sol.maxDepth(root);

    return 0;
}
//
// Created by polarnight on 24-7-30, 上午10:58.
//

#include <iostream>
#include <vector>
#include <queue>

#include "generate_tree_node.h"

using namespace std;

class Node {
 public:
  int val;
  vector<Node *> children;

  Node() {}

  Node(int _val) {
	val = _val;
  }

  Node(int _val, vector<Node *> _children) {
	val = _val;
	children = _children;
  }
};

class Solution {
 public:
  vector<vector<int>> levelOrder(Node *root) {
	queue<Node *> que;
	vector<vector<int>> res;

	if (root) que.push(root);
	while (!que.empty()) {
	  int queue_size = que.size();
	  vector<int> tmp;

	  for (int i = 0; i < queue_size; i++) {
		Node *node = que.front();
		que.pop();
		tmp.push_back(node->val);
		for (auto &vec : node->children)
		  que.push(vec);
	  }
	  res.push_back(tmp);
	}
	return res;
  }
};

int main07() {
  Node *root = new Node(1);
  Node *node1 = new Node(3);
  Node *node2 = new Node(2);
  Node *node3 = new Node(4);
  Node *node4 = new Node(5);
  Node *node5 = new Node(6);

  root->children = {node1, node2, node3};
  node1->children = {node4, node5};

  Solution sol;
  auto res = sol.levelOrder(root);

  for (auto &vec : res) {
	for (auto &var : vec) {
	  cout << var << " ";
	}
	cout << endl;
  }

  return 0;
}

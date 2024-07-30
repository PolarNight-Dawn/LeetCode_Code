//
// Created by polarnight on 24-7-30, 上午11:31.
//

#include <iostream>
#include <queue>

#include "generate_tree_node.h"

using namespace std;

class Node {
 public:
  int val;
  Node *left;
  Node *right;
  Node *next;

  Node() : val(0), left(NULL), right(NULL), next(NULL) {}

  Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

  Node(int _val, Node *_left, Node *_right, Node *_next)
	  : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
 public:
  Node *connect(Node *root) {
	if (!root) return root;
	queue<Node *> que;
	que.push(root);

	while (!que.empty()) {
	  int que_size = que.size();

	  for (int i = 0; i < que_size; i++) {
		Node *node = que.front();
		que.pop();
		if (i < que_size - 1) node->next = que.front();
		if (node->left) que.push(node->left);
		if (node->right) que.push(node->right);
	  }
	}
	return root;
  }
};

int main() {

}
//
// Created by polarnight on 24-7-30, 上午10:27.
//

#include <iostream>
#include <vector>
#include <queue>

#include "generate_tree_node.h"

using namespace std;

class Solution {
 public:
  vector<int> rightSideView(const std::shared_ptr<gtn::TreeNodeShared> &root) {
	queue<std::shared_ptr<gtn::TreeNodeShared>> que;
	vector<int> res;

	if (root) que.push(root);
	while (!que.empty()) {
	  int que_size = que.size();

	  for (int i = 0; i < que_size; i++) {
		std::shared_ptr<gtn::TreeNodeShared> node = que.front();
		que.pop();
		if (i == que_size - 1) res.push_back(node->val);
		if (node->left) que.push(node->left);
		if (node->right) que.push(node->right);
	  }
	}
	return res;
  }
};

int main05() {
  std::shared_ptr<gtn::TreeNodeShared> root = std::make_shared<gtn::TreeNodeShared>(1);
  root->left = std::make_shared<gtn::TreeNodeShared>(2);
  root->left->right = std::make_shared<gtn::TreeNodeShared>(5);
  root->right = std::make_shared<gtn::TreeNodeShared>(3);
  root->right->right = std::make_shared<gtn::TreeNodeShared>(4);

  Solution sol;
  auto res = sol.rightSideView(root);

  for (auto vec : res)
	cout << vec << " ";
  cout << endl;

  return 0;
}
//
// Created by polarnight on 24-7-30, 上午10:16.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#include "generate_tree_node.h"

using namespace std;

class Solution {
 public:
  vector<vector<int>> levelOrderBottom(const std::shared_ptr<gtn::TreeNodeShared> &root) {
	queue<std::shared_ptr<gtn::TreeNodeShared>> que;
	vector<vector<int>> res;

	if (root) que.push(root);
	while (!que.empty()) {
	  int queue_size = que.size();
	  vector<int> tmp;

	  for (int i = 0; i < queue_size; i++) {
		std::shared_ptr<gtn::TreeNodeShared> node = que.front();
		que.pop();
		tmp.push_back(node->val);
		if (node->left) que.push(node->left);
		if (node->right) que.push(node->right);
	  }
	  res.push_back(tmp);
	}
	std::reverse(res.begin(), res.end());
	return res;
  }
};

int main04() {
  std::shared_ptr<gtn::TreeNodeShared> root = std::make_shared<gtn::TreeNodeShared>(3);
  root->left = std::make_shared<gtn::TreeNodeShared>(9);
  root->right = std::make_shared<gtn::TreeNodeShared>(20);
  root->right->left = std::make_shared<gtn::TreeNodeShared>(15);
  root->right->right = std::make_shared<gtn::TreeNodeShared>(7);

  Solution sol;
  auto res = sol.levelOrderBottom(root);

  for (auto vec : res) {
	for (auto var : vec) {
	  cout << var << " ";
	}
	cout << endl;
  }

  return 0;
}
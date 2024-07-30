//
// Created by polarnight on 24-7-30, 上午11:20.
//

#include <iostream>
#include <vector>
#include <queue>

#include "generate_tree_node.h"

using namespace std;

class Solution {
 public:
  vector<int> largestValues(const std::shared_ptr<gtn::TreeNodeShared> &root) {
	queue<std::shared_ptr<gtn::TreeNodeShared>> que;
	vector<int> res;

	if (root) que.push(root);
	while (!que.empty()) {
	  int que_size = que.size();
	  int max_num = INT32_MIN;

	  for (int i = 0; i < que_size; i++) {
		std::shared_ptr<gtn::TreeNodeShared> node = que.front();
		que.pop();
		max_num = max(max_num, node->val);
		if (node->left) que.push(node->left);
		if (node->right) que.push(node->right);
	  }
	  res.push_back(max_num);
	}
	return res;
  }
};

int main08() {
  std::shared_ptr<gtn::TreeNodeShared> root = std::make_shared<gtn::TreeNodeShared>(1);
  root->left = std::make_shared<gtn::TreeNodeShared>(3);
  root->left->left = std::make_shared<gtn::TreeNodeShared>(5);
  root->left->right = std::make_shared<gtn::TreeNodeShared>(3);
  root->right = std::make_shared<gtn::TreeNodeShared>(2);
  root->right->right = std::make_shared<gtn::TreeNodeShared>(9);

  Solution sol;
  auto res = sol.largestValues(root);

  for (auto vec : res)
	cout << vec << " ";
  cout << endl;

  return 0;
}
